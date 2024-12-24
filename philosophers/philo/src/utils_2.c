/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:22:03 by sede-los          #+#    #+#             */
/*   Updated: 2024/11/21 01:22:23 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	action_print(t_rules *rules, int id, char *str)
{
	pthread_mutex_lock(&(rules->writing));
	if (!(rules->flag_died))
	{
		printf("%lli ", time_diff(rules->first_timestamp, timestamp()));
		printf("%i ", id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(rules->writing));
	return ;
}

int	fork_order(int fork_1, int fork_2, int order)
{
	int	lower;
	int	higher;

	if (fork_1 < fork_2)
	{
		lower = fork_1;
		higher = fork_2;
	}
	else
	{
		lower = fork_2;
		higher = fork_1;
	}
	if (order == 1)
		return (lower);
	else if (order == 2)
		return (higher);
	else
		return (-1);
}

void	check_all_ate(t_rules *r, t_philo *p)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(r->meal_check));
	while (r->nb_all_eat != -1 && i < r->nb_philos
		&& p[i].x_ate >= r->nb_all_eat)
		i++;
	pthread_mutex_unlock(&(r->meal_check));
	if (i == r->nb_philos)
		r->flag_all_eat = 1;
}

void	handle_single_philo(t_philo	*phi, t_rules *rules)
{
	action_print(rules, phi->id, "has taken a fork");
	smart_sleep(rules->t_to_death, rules);
	action_print(rules, phi->id, "died");
	pthread_mutex_lock(&(rules->meal_check));
	rules->flag_died = 1;
	pthread_mutex_unlock(&(rules->meal_check));
}
