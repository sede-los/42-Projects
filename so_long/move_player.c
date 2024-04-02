/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:25:50 by sede-los          #+#    #+#             */
/*   Updated: 2024/03/22 16:08:35 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_right(t_vars *vars)
{
	if (vars->matrix[vars->p_y][vars->p_x + 1] == '0'
		|| vars->matrix[vars->p_y][vars->p_x + 1] == 'C')
	{
		if (vars->matrix[vars->p_y][vars->p_x + 1] == 'C')
			vars->player_coins++;
		vars->matrix[vars->p_y][vars->p_x] = '0';
		vars->matrix[vars->p_y][vars->p_x + 1] = 'P';
		vars->p_x++;
		vars->steps++;
		ft_printf("Número de pasos: %i\n", vars->steps);
	}
	else if (vars->matrix[vars->p_y][vars->p_x + 1] == '1')
		ft_printf("No puedes moverte en esa dirección\n");
	else if (vars->matrix[vars->p_y][vars->p_x + 1] == 'E')
	{
		if (vars->player_coins == vars->map_coins)
		{
			ft_printf("Felicidades, has completado el nivel en %i pasos\n",
				vars->steps + 1);
			exit_game(vars);
		}
		else
			ft_printf("No has recogido todos los coleccionables\n");
	}
	print_matrix(vars);
}

void	player_left(t_vars *vars)
{
	if (vars->matrix[vars->p_y][vars->p_x - 1] == '0'
		|| vars->matrix[vars->p_y][vars->p_x - 1] == 'C')
	{
		if (vars->matrix[vars->p_y][vars->p_x - 1] == 'C')
			vars->player_coins++;
		vars->matrix[vars->p_y][vars->p_x] = '0';
		vars->matrix[vars->p_y][vars->p_x - 1] = 'P';
		vars->p_x--;
		vars->steps++;
		ft_printf("Número de pasos: %i\n", vars->steps);
	}
	else if (vars->matrix[vars->p_y][vars->p_x - 1] == '1')
		ft_printf("No puedes moverte en esa dirección\n");
	else if (vars->matrix[vars->p_y][vars->p_x - 1] == 'E')
	{
		if (vars->player_coins == vars->map_coins)
		{
			ft_printf("Felicidades, has completado el nivel en %i pasos\n",
				vars->steps + 1);
			exit_game(vars);
		}
		else
			ft_printf("No has recogido todos los coleccionables\n");
	}
	print_matrix(vars);
}

void	player_up(t_vars *vars)
{
	if (vars->matrix[vars->p_y - 1][vars->p_x] == '0'
		|| vars->matrix[vars->p_y - 1][vars->p_x] == 'C')
	{
		if (vars->matrix[vars->p_y - 1][vars->p_x] == 'C')
			vars->player_coins++;
		vars->matrix[vars->p_y][vars->p_x] = '0';
		vars->matrix[vars->p_y - 1][vars->p_x] = 'P';
		vars->p_y--;
		vars->steps++;
		ft_printf("Número de pasos: %i\n", vars->steps);
	}
	else if (vars->matrix[vars->p_y - 1][vars->p_x] == '1')
		ft_printf("No puedes moverte en esa dirección\n");
	else if (vars->matrix[vars->p_y - 1][vars->p_x] == 'E')
	{
		if (vars->player_coins == vars->map_coins)
		{
			ft_printf("Felicidades, has completado el nivel en %i pasos\n",
				vars->steps + 1);
			exit_game(vars);
		}
		else
			ft_printf("No has recogido todos los coleccionables\n");
	}
	print_matrix(vars);
}

void	player_down(t_vars *vars)
{
	if (vars->matrix[vars->p_y + 1][vars->p_x] == '0'
		|| vars->matrix[vars->p_y + 1][vars->p_x] == 'C')
	{
		if (vars->matrix[vars->p_y + 1][vars->p_x] == 'C')
			vars->player_coins++;
		vars->matrix[vars->p_y][vars->p_x] = '0';
		vars->matrix[vars->p_y + 1][vars->p_x] = 'P';
		vars->p_y++;
		vars->steps++;
		ft_printf("Número de pasos: %i\n", vars->steps);
	}
	else if (vars->matrix[vars->p_y + 1][vars->p_x] == '1')
		ft_printf("No puedes moverte en esa dirección\n");
	else if (vars->matrix[vars->p_y + 1][vars->p_x] == 'E')
	{
		if (vars->player_coins == vars->map_coins)
		{
			ft_printf("Felicidades, has completado el nivel en %i pasos\n",
				vars->steps + 1);
			exit_game(vars);
		}
		else
			ft_printf("No has recogido todos los coleccionables\n");
	}
	print_matrix(vars);
}

void	move_player(t_vars *vars, int keycode)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		player_up(vars);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		player_down(vars);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		player_left(vars);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		player_right(vars);
}
