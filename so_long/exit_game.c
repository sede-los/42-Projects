/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:46:05 by sede-los          #+#    #+#             */
/*   Updated: 2024/03/22 16:02:40 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_vars *vars)
{
	free_matrix(vars->matrix, vars);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
