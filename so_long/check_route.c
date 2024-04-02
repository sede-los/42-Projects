/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:26:06 by sede-los          #+#    #+#             */
/*   Updated: 2024/04/02 21:38:52 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**duplicate_matrix(t_vars *vars)
{
	char	**dup_matrix;
	int		i;
	int		j;

	i = 0;
	dup_matrix = (char **)malloc(sizeof(char *) * vars->win_height);
	if (!dup_matrix)
		ft_error(4);
	while (i < vars->win_height)
	{
		dup_matrix[i] = (char *)malloc(sizeof(char) * vars->win_width);
		if (!dup_matrix[i])
			ft_error(4);
		j = 0;
		while (j < vars->win_width)
		{
			dup_matrix[i][j] = vars->matrix[i][j];
			j++;
		}
		i++;
	}
	return (dup_matrix);
}

void	free_matrix(char **matrix, t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->win_height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	flood_fill(char **matrix, int pos_y, int pos_x)
{
	if (matrix[pos_y][pos_x] == '1' || matrix[pos_y][pos_x] == 'F')
		return ;
	if (matrix[pos_y][pos_x] == 'E')
	{
		matrix[pos_y][pos_x] = 'F';
		return ;
	}
	matrix[pos_y][pos_x] = 'F';
	flood_fill(matrix, pos_y + 1, pos_x);
	flood_fill(matrix, pos_y - 1, pos_x);
	flood_fill(matrix, pos_y, pos_x + 1);
	flood_fill(matrix, pos_y, pos_x - 1);
}

void	check_route(t_vars *vars)
{
	char	**dup_matrix;
	int		i;
	int		j;

	i = 0;
	dup_matrix = duplicate_matrix(vars);
	flood_fill(dup_matrix, vars->p_y, vars->p_x);
	while (i < vars->win_height)
	{
		j = 0;
		while (j < vars->win_width)
		{
			if (dup_matrix[i][j] == 'E' || dup_matrix[i][j] == 'C')
			{
				free_matrix(vars->matrix, vars);
				ft_error(7);
			}
			j++;
		}
		i++;
	}
	free_matrix(dup_matrix, vars);
}

void	check_extension(char *map_name)
{
	int	i;

	i = ft_strlen(map_name);
	if (i < 4)
		ft_error(6);
	if (ft_strncmp(&map_name[i - 4], ".ber", 4))
		ft_error(6);
}
