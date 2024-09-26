/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:17:22 by sede-los          #+#    #+#             */
/*   Updated: 2024/09/26 18:16:40 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Check if exit code is valid, allow only one type of sign*/
static int	ft_strisnum(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && !sign)
			sign = 1;
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*Different return codes to be as much "bash compliant" as possible*/
static int	exit_error(int flag, char *str)
{
	if (flag == EXIT_MANY_ARGS)
	{
		_error(EXIT_ARGS_ERROR);
		return (1);
	}
	if (flag == EXIT_BADARGS)
	{
		_error(EXIT_ALPHA_ERROR, str);
		return (2);
	}
	return (0);
}

int	ft_exit(char **args)
{
	int	exit_s;

	if (args[1] && !(ft_strisnum(args[1])))
		exit (exit_error(EXIT_BADARGS, args[1]));
	if (args[1] && args[2])
		return (exit_error(EXIT_MANY_ARGS, NULL));
	else if (args[1])
	{
		exit_s = ft_atoi(args[1]);
		if (exit_s < 0)
			exit_s = 156;
		exit(exit_s);
	}
	else
	{
		ft_putendl_fd("exit", 1);
		exit(0);
	}
	return (0);
}
