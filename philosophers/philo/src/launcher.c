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

void	philo_eats(t_philo *phi)
{
	t_rules	*rules;

	rules = phi->rules;
	pthread_mutex_lock(&(rules->forks[phi->left_fork_id]));
	action_print(rules, phi->id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[phi->right_fork_id]));
	action_print(rules, phi->id, "has taken a fork");
	pthread_mutex_lock(&(rules->meal_check));
	action_print(rules, phi->id, "is eating");
	phi->t_last_meal = timestamp();
	pthread_mutex_unlock(&(rules->meal_check));
	smart_sleep(rules->t_to_eat, rules);
	phi->x_ate++;
	pthread_mutex_unlock(&(rules->forks[phi->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[phi->right_fork_id]));
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
		rules->flag_died = 1;
		return (NULL);
	}
	if (phi->id % 2)
		usleep(15000);
	while (!(rules->flag_died))
	{
		philo_eats(phi);
		if (rules->flag_all_eat)
			break ;
		action_print(rules, phi->id, "is sleeping");
		smart_sleep(rules->t_to_sleep, rules);
		action_print(rules, phi->id, "is tinking");
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
		if (r->flag_died)
			break ;
		i = 0;
		while (r->nb_all_eat != -1 && i < r->nb_philos
			&& p[i].x_ate >= r->nb_all_eat)
			i++;
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
		phi[i].t_last_meal = timestamp();
		i++;
	}
	death_checker(rules, rules->philos);
	exit_launcher(rules, rules->philos);
	return (0);
}
