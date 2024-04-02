/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:27:58 by sede-los          #+#    #+#             */
/*   Updated: 2024/03/22 16:33:53 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_vertical(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < vars->win_width)
	{
		if (vars->matrix[i][j] != '1')
			ft_error_free(9, vars);
		j++;
	}
	i = vars->win_height - 1;
	j = 0;
	while (j < vars->win_width)
	{
		if (vars->matrix[i][j] != '1')
			ft_error_free(9, vars);
		j++;
	}
}

void	check_horizontal(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->win_height)
	{
		if (vars->matrix[i][j] != '1')
			ft_error_free(9, vars);
		i++;
	}
	i = 0;
	j = vars->win_width - 1;
	while (i < vars->win_height)
	{
		if (vars->matrix[i][j] != '1')
			ft_error_free(9, vars);
		i++;
	}
}

void	check_border(t_vars *vars)
{
	check_vertical(vars);
	check_horizontal(vars);
}
