/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 05:22:25 by sede-los          #+#    #+#             */
/*   Updated: 2024/10/04 05:22:27 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	parse_checker(char	**argv)
{
	if (argv[1] <= 0 || argv[1] > PHILO_MAX || !(str_is_num(argv[1])))
		return (write_error("Invalid number of philosophers"));
	if (argv[2] <= 0 || !(str_is_num(argv[2])))
		return (write_error("Invalid time to die"));
	if (argv[3] <= 0 || !(str_is_num(argv[3])))
		return (write_error("Invalid time to eat"));
	if (argv[4] <= 0 || !(str_is_num(argv[4])))
		return (write_error("Invalid time to sleep"));
	if (argv[5] && (argv[2] <= 0 || !(str_is_num(argv[2]))))
		return (write_error("Invalid number of time each philo must eat"));
}
