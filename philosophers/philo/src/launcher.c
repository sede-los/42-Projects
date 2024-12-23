/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:02:54 by sede-los          #+#    #+#             */
/*   Updated: 2024/11/20 21:02:57 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	philo_eats(t_philo *phi, t_rules *rules)
{
	int	first;
	int	second;

	pthread_mutex_lock(&(rules->meal_check));
	if (rules->nb_all_eat != -1 && phi->x_ate >= rules->nb_all_eat)
	{
		pthread_mutex_unlock(&(rules->meal_check));
		return (0);
	}
	pthread_mutex_unlock(&(rules->meal_check));
	first = fork_order(phi->left_fork_id, phi->right_fork_id, 1);
	second = fork_order(phi->left_fork_id, phi->right_fork_id, 2);
	pthread_mutex_lock(&(rules->forks[first]));
	action_print(rules, phi->id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[second]));
	action_print(rules, phi->id, "has taken a fork");
	pthread_mutex_lock(&(rules->meal_check));
	action_print(rules, phi->id, "is eating");
	phi->t_last_meal = timestamp();
	phi->x_ate++;
	pthread_mutex_unlock(&(rules->meal_check));
	smart_sleep(rules->t_to_eat, rules);
	pthread_mutex_unlock(&(rules->forks[second]));
	pthread_mutex_unlock(&(rules->forks[first]));
	return (1);
}

void	*p_thread(void *void_phi)
{
	t_philo	*phi;
	t_rules	*rules;

	phi = (t_philo *)void_phi;
	rules = phi->rules;
	if (rules->nb_philos == 1)
	{
		action_print(rules, phi->id, "has taken a fork");
		smart_sleep(rules->t_to_death, rules);
		action_print(rules, phi->id, "died");
		pthread_mutex_lock(&(rules->meal_check));
		rules->flag_died = 1;
		pthread_mutex_unlock(&(rules->meal_check));
		return (NULL);
	}
	if (phi->id % 2)
		usleep(15000);
	while (!(rules->flag_died))
	{
		if (philo_eats(phi, rules) == 0)
			break ;
		action_print(rules, phi->id, "is sleeping");
		smart_sleep(rules->t_to_sleep, rules);
		action_print(rules, phi->id, "is thinking");
	}
	return (NULL);
}

void	death_checker(t_rules *r, t_philo *p)
{
	int	i;

	while (!(r->flag_all_eat))
	{
		i = -1;
		while (++i < r->nb_philos && !(r->flag_died))
		{
			pthread_mutex_lock(&(r->meal_check));
			if (time_diff(p[i].t_last_meal, timestamp()) > r->t_to_death)
			{
				action_print(r, i, "died");
				r->flag_died = 1;
			}
			pthread_mutex_unlock(&(r->meal_check));
			usleep(100);
		}
		pthread_mutex_lock(&(r->meal_check));
		if (r->flag_died)
		{
			pthread_mutex_unlock(&(r->meal_check));
			break ;
		}
		pthread_mutex_unlock(&(r->meal_check));
		i = 0;
		pthread_mutex_lock(&(r->meal_check));
		while (r->nb_all_eat != -1 && i < r->nb_philos
			&& p[i].x_ate >= r->nb_all_eat)
			i++;
		pthread_mutex_unlock(&(r->meal_check));
		if (i == r->nb_philos)
			r->flag_all_eat = 1;
	}
}

void	exit_launcher(t_rules *rules, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < rules->nb_philos)
	{
		pthread_join(philos[i].pthread_id, NULL);
		i++;
	}
	i = 0;
	while (i < rules->nb_philos)
	{
		pthread_mutex_destroy(&(rules->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(rules->writing));
	pthread_mutex_destroy(&(rules->meal_check));
}

int	launcher(t_rules *rules)
{
	int		i;
	t_philo	*phi;

	phi = rules->philos;
	i = 0;
	rules->first_timestamp = timestamp();
	while (i < rules->nb_philos)
	{
		if (pthread_create(&(phi[i].pthread_id), NULL, p_thread, &(phi[i])))
			return (1);
		pthread_mutex_lock(&(rules->meal_check));
		phi[i].t_last_meal = timestamp();
		i++;
		pthread_mutex_unlock(&(rules->meal_check));
	}
	death_checker(rules, rules->philos);
	exit_launcher(rules, rules->philos);
	return (0);
}
