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
