/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:46:41 by sede-los          #+#    #+#             */
/*   Updated: 2024/03/31 04:10:19 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_char(char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E'
		&& c != 'P' && c != 10 && c != 0)
		ft_error(3);
}

void	check_map_size(t_vars *vars)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(vars->map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_error(1);
	vars->win_width = ft_strlen(line) - 1;
	vars->win_height = 0;
	while (line)
	{
		i = 0;
		while (line[i++])
			check_char(line[i]);
		if ((int)ft_strlen(line) - 1 != vars->win_width)
			ft_error(2);
		vars->win_height++;
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close(fd);
}

void	malloc_map(t_vars *vars)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(vars->map_path, O_RDONLY);
	i = 0;
	vars->matrix = (char **)malloc(sizeof(char *) * (vars->win_height));
	if (!vars->matrix)
		ft_error(4);
	while (i < vars->win_height)
	{
		line = get_next_line(fd);
		if (!line)
			ft_error(1);
		vars->matrix[i] = ft_strdup(line);
		if (!vars->matrix[i])
			ft_error(4);
		vars->matrix[i][vars->win_width] = '\0';
		i++;
		free(line);
	}
	line = NULL;
	close(fd);
}

void	count_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->win_height)
	{
		j = 0;
		while (j < vars->win_width)
		{
			if (vars->matrix[i][j] == 'C')
				vars->map_coins++;
			else if (vars->matrix[i][j] == 'P')
			{
				vars->map_player++;
				vars->p_x = j;
				vars->p_y = i;
			}
			else if (vars->matrix[i][j] == 'E')
				vars->map_exit++;
			j++;
		}
		i++;
	}
	if (vars->map_player != 1 || vars->map_exit != 1 || vars->map_coins < 1)
		ft_error(5);
}
