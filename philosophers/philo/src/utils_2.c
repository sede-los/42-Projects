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
