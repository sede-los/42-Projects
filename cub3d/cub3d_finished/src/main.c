/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:06:21 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/12 10:06:23 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	errors(char	*str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	return (1);
}

void	more_free(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
		game->map = NULL;
	}
	if (game->player)
		free(game->player);
	if (game->mlx)
		free(game->mlx);
}

void	free_structure(t_game *game)
{
	if (game->textures)
	{
		if (game->textures->north)
			free(game->textures->north);
		if (game->textures->south)
			free(game->textures->south);
		if (game->textures->east)
			free(game->textures->east);
		if (game->textures->west)
			free(game->textures->west);
		free(game->textures);
	}
	if (game->is_map)
		free(game->is_map);
	if (game->is_texture)
		free(game->is_texture);
	more_free(game);
}

void	init_structure(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->textures = ft_calloc(1, sizeof(t_textures));
	game->mlx = ft_calloc(1, sizeof(t_mlx));
	game->player = ft_calloc(1, sizeof(t_player));
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (errors("Add only one argument ended in .cub\n"));
	init_structure(&game);
	if (parse(&game, argv[1]) == 1)
	{
		free_structure(&game);
		return (1);
	}
	if (render_map(&game) == 1)
	{
		free_structure(&game);
		return (1);
	}
	free_structure(&game);
}
