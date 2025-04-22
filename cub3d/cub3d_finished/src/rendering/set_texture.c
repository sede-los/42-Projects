/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:25:39 by isainz-r          #+#    #+#             */
/*   Updated: 2025/04/15 12:25:41 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

unsigned int	get_pixel_from_texture(int wall_plane, int texture_x,
	int texture_y, t_game *game)
{
	t_info			texture;
	char			*image;

	if (wall_plane == NORTH)
		texture = game->info[0];
	if (wall_plane == SOUTH)
		texture = game->info[1];
	if (wall_plane == EAST)
		texture = game->info[2];
	if (wall_plane == WEST)
		texture = game->info[3];
	image = texture.data;
	image += (texture_x * (texture.bpp / 8)) + (texture_y * texture.size_line);
	return (*(unsigned int *)image);
}

void	is_north(float dist, float plane_x,	int ray_iteration, t_game *game)
{
	int	wall_height;
	int	wall_y;
	int	i;

	if (dist < 1)
		dist = 1;
	wall_height = HEIGHT / dist;
	wall_y = (HEIGHT - wall_height) / 2;
	i = 0;
	while (i < wall_height)
	{
		put_pixel(ray_iteration, wall_y,
			get_pixel_from_texture(NORTH, plane_x, 64 * i / wall_height, game),
			game);
		wall_y++;
		i++;
	}
}

void	is_south(float dist, float plane_x,	int ray_iteration, t_game *game)
{
	int	wall_height;
	int	wall_y;
	int	i;

	if (dist < 1)
		dist = 1;
	wall_height = HEIGHT / dist;
	wall_y = (HEIGHT - wall_height) / 2;
	i = 0;
	while (i < wall_height)
	{
		put_pixel(ray_iteration, wall_y,
			get_pixel_from_texture(SOUTH, plane_x, 64 * i / wall_height, game),
			game);
		wall_y++;
		i++;
	}
}

void	is_east(float dist, float plane_x, int ray_iteration, t_game *game)
{
	int	wall_height;
	int	wall_y;
	int	i;

	if (dist < 1)
		dist = 1;
	wall_height = HEIGHT / dist;
	wall_y = (HEIGHT - wall_height) / 2;
	i = 0;
	while (i < wall_height)
	{
		put_pixel(ray_iteration, wall_y,
			get_pixel_from_texture(EAST, plane_x, 64 * i / wall_height, game),
			game);
		wall_y++;
		i++;
	}
}

void	is_west(float dist, float plane_x, int ray_iteration, t_game *game)
{
	int	wall_height;
	int	wall_y;
	int	i;

	if (dist < 1)
		dist = 1;
	wall_height = HEIGHT / dist;
	wall_y = (HEIGHT - wall_height) / 2;
	i = 0;
	while (i < wall_height)
	{
		put_pixel(ray_iteration, wall_y,
			get_pixel_from_texture(WEST, plane_x, 64 * i / wall_height, game),
			game);
		wall_y++;
		i++;
	}
}
