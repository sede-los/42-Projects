/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:22:33 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/14 17:22:35 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

int	compare(char **splitted, t_game *game)
{
	if (((!ft_strncmp(splitted[0], "NO", 2)
				|| !ft_strncmp(splitted[0], "SO", 2)
				|| !ft_strncmp(splitted[0], "EA", 2)
				|| !ft_strncmp(splitted[0], "WE", 2))
			&& ft_strlen(splitted[0]) == 2)
		|| ((!ft_strncmp(splitted[0], "F", 1)
				|| !ft_strncmp(splitted[0], "C", 1))
			&& ft_strlen(splitted[0]) == 1))
	{
		if (!splitted[0] || !splitted[1] || splitted[2])
			return (errors("Incorrect textures\n"));
	}
	if (!ft_strncmp(splitted[0], "NO", 2) && ft_strlen(splitted[0]) == 2
		&& game->textures->north)
		return (errors("More than one texture\n"));
	if (!ft_strncmp(splitted[0], "SO", 2) && ft_strlen(splitted[0]) == 2
		&& game->textures->south)
		return (errors("More than one texture\n"));
	if (!ft_strncmp(splitted[0], "EA", 2) && ft_strlen(splitted[0]) == 2
		&& game->textures->east)
		return (errors("More than one texture\n"));
	if (!ft_strncmp(splitted[0], "WE", 2) && ft_strlen(splitted[0]) == 2
		&& game->textures->west)
		return (errors("More than one texture\n"));
	return (0);
}

int	set_texture(char **splitted, t_game *game)
{
	if (compare(splitted, game) == 1)
		return (free_matrix(splitted), 1);
	if (!ft_strncmp(splitted[0], "NO", 2) && ft_strlen(splitted[0]) == 2)
		game->textures->north = ft_strdup(splitted[1]);
	else if (!ft_strncmp(splitted[0], "SO", 2) && ft_strlen(splitted[0]) == 2)
		game->textures->south = ft_strdup(splitted[1]);
	else if (!ft_strncmp(splitted[0], "EA", 2) && ft_strlen(splitted[0]) == 2)
		game->textures->east = ft_strdup(splitted[1]);
	else if (!ft_strncmp(splitted[0], "WE", 2) && ft_strlen(splitted[0]) == 2)
		game->textures->west = ft_strdup(splitted[1]);
	else if (check_colors(splitted, game) == 1)
		return (free_matrix(splitted), 1);
	return (free_matrix(splitted), 0);
}

int	check_again(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->textures->celing[i] == -1)
			return (errors("Celing not correct\n"));
		if (game->textures->floor[i] == -1)
			return (errors("Floor not correct\n"));
		i++;
	}
	if (!game->textures->celing[3] || !game->textures->floor[3])
		return (errors("Not celing or floor\n"));
	if (!game->is_map)
		return (errors("Map not added\n"));
	return (0);
}

int	check_textures(t_game *game)
{
	int		i;
	char	**split_texture;

	i = 0;
	split_texture = ft_split(game->is_texture, '\n');
	if (!split_texture || !split_texture[0])
		return (errors("Map not ok\n"));
	while (split_texture[i])
	{
		if (set_texture(ft_split(split_texture[i], ' '), game) == 1)
			return (free_matrix(split_texture), 1);
		i++;
	}
	if (check_again(game) == 1)
		return (free_matrix(split_texture), 1);
	return (free_matrix(split_texture), 0);
}
