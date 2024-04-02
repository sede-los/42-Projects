/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:17:00 by sede-los          #+#    #+#             */
/*   Updated: 2024/03/31 00:12:13 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_matrix(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->win_height)
	{
		j = 0;
		while (j < vars->win_width)
		{
			print_images(vars, vars->matrix[i][j], i, j);
			j++;
		}
		i++;
	}
}

void	initialize_images(t_vars *vars)
{
	vars->image_0.path = "xpm/floor.xpm";
	vars->image_0.width = SIZE;
	vars->image_0.height = SIZE;
	vars->image_0.img = mlx_xpm_file_to_image(vars->mlx, vars->image_0.path,
			&vars->image_0.width, &vars->image_0.height);
	vars->image_1.path = "xpm/wall.xpm";
	vars->image_1.width = SIZE;
	vars->image_1.height = SIZE;
	vars->image_1.img = mlx_xpm_file_to_image(vars->mlx, vars->image_1.path,
			&vars->image_1.width, &vars->image_1.height);
	vars->image_c.path = "xpm/collectable.xpm";
	vars->image_c.width = SIZE;
	vars->image_c.height = SIZE;
	vars->image_c.img = mlx_xpm_file_to_image(vars->mlx, vars->image_c.path,
			&vars->image_c.width, &vars->image_c.height);
	vars->image_e.path = "xpm/exit.xpm";
	vars->image_e.width = SIZE;
	vars->image_e.height = SIZE;
	vars->image_e.img = mlx_xpm_file_to_image(vars->mlx, vars->image_e.path,
			&vars->image_e.width, &vars->image_e.height);
	vars->image_p.path = "xpm/character.xpm";
	vars->image_p.width = SIZE;
	vars->image_p.height = SIZE;
	vars->image_p.img = mlx_xpm_file_to_image(vars->mlx, vars->image_p.path,
			&vars->image_p.width, &vars->image_p.height);
}

int	key_hook(int k, t_vars *vars)
{
	if (k == KEY_ESC)
		exit_game(vars);
	else if (k == 13 || k == 0 || k == 1 || k == 2 || k == 123
		|| k == 124 || k == 125 || k == 126)
		move_player(vars, k);
	return (0);
}

int	close_window_event(t_vars *vars)
{
	exit_game(vars);
	return (0);
}

void	initialize_game(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (SIZE * vars->win_width),
			(SIZE * vars->win_height), "The Game");
	initialize_images(vars);
	print_matrix(vars);
	mlx_hook(vars->win, 17, 1L << 17, close_window_event, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop(vars->mlx);
}
