/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:49:34 by isainz-r          #+#    #+#             */
/*   Updated: 2025/04/14 14:49:37 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

int	check_line(char *line)
{
	int	comma;
	int	i;

	comma = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (-1);
	return (0);
}

int	add_color(int num_color, char *line)
{
	int	comma;
	int	i;
	int	n;

	comma = 0;
	i = 0;
	n = 0;
	if (check_line(line) == -1)
		return (-1);
	while (line[i])
	{
		if ((!(line[i] >= '0' && line[i] <= '9') && line[i] != ',') || n > 255)
			return (-1);
		if (line[i] >= '0' && line[i] <= '9')
			n = n * 10 + (line[i] - '0');
		if (line[i] == ',' && num_color == comma)
			break ;
		if (line[i] == ',')
		{
			n = 0;
			comma++;
		}
		i++;
	}
	return (n);
}

int	color(char **split_line, t_game *game)
{
	if ((!game->textures->north || !game->textures->south
			|| !game->textures->east || !game->textures->west))
		return (errors("Textures aren't written correctly\n"));
	if ((!ft_strncmp(split_line[0], "F", 1)
			|| !ft_strncmp(split_line[0], "C", 1))
		&& ft_strlen(split_line[0]) == 1)
	{
		if (!split_line[0] || !split_line[1] || split_line[2])
			return (errors("Colors aren't written correctly\n"));
	}
	return (0);
}

int	check_colors(char **split_line, t_game *game)
{
	if (color(split_line, game) == 1)
		return (1);
	if (!ft_strncmp(split_line[0], "C", 1) && ft_strlen(split_line[0]) == 1)
	{
		if (game->textures->celing[3] == 255)
			return (errors("More than one celing\n"));
		game->textures->celing[0] = add_color(0, split_line[1]);
		game->textures->celing[1] = add_color(1, split_line[1]);
		game->textures->celing[2] = add_color(2, split_line[1]);
		game->textures->celing[3] = 255;
	}
	if (!ft_strncmp(split_line[0], "F", 1) && ft_strlen(split_line[0]) == 1)
	{
		if (game->textures->floor[3] == 255)
			return (errors("More than one floor\n"));
		game->textures->floor[0] = add_color(0, split_line[1]);
		game->textures->floor[1] = add_color(1, split_line[1]);
		game->textures->floor[2] = add_color(2, split_line[1]);
		game->textures->floor[3] = 255;
	}
	return (0);
}
