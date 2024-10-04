/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 05:57:45 by sede-los          #+#    #+#             */
/*   Updated: 2024/10/04 05:57:48 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	init_mutex(t_rules *rules)
{
	int	i;

	i = rules->nb_philos;
	while(--i >= 0)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(rules->meal_check)), NULL)
		return (1);
	if (pthread_mutex_init(&(rules->writing)), NULL)
		return (1);
	return (0);
}

int init_philosophers(t_rules *rules)
{
	int i;

	i = rules->nb_philos;
	while(--i >= 0)
	{
		rules->philos->id = i;
		rules->philos->left_fork_id = i;
		rules->philos->right_fork_id = (i + 1) % rules->nb_philos;
		rules->philos->t_last_meal = 0;
		rules->philos->x_ate = 0;
		rules->philos->rules = rules;
	}
	return (0);
}

int	init_all(t_rules *rules, char **argv)
{
	rules->nb_philos = ft_atoi(argv[1]);
	rules->t_to_death = ft_atoi(argv[2]);
	rules->t_to_eat = ft_atoi(argv[3]);
	rules->t_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		rules->nb_all_eat = ft_atoi(argv[5]);
	else
		rules->nb_all_eat = -1;
	rules->all_eat = 0;
	rules->flag_died = 0;
	if (init_mutex(rules))
		return(write_error("Fatal error when intializing mutex"));
	init_philosophers(rules);
}