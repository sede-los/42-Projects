/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:01:26 by isainz-r          #+#    #+#             */
/*   Updated: 2025/04/11 10:01:28 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

int	is_a_block(t_game *game, float ray_x, float ray_y)
{
	if (ray_x > game->map_width || ray_y > game->map_height
		|| ray_x < 0 || ray_y < 0)
		return (1);
	return (game->map[(int)ray_y][(int)ray_x] == '1');
}

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	index = (y * game->mlx->size_line) + (x * (game->mlx->bpp / 8));
	if (index < 0 || index >= (HEIGHT * game->mlx->size_line))
		return ;
	game->mlx->data[index] = color & 0xFF;
	game->mlx->data[index + 1] = (color >> 8) & 0xFF;
	game->mlx->data[index + 2] = (color >> 16) & 0xFF;
}

void	set_the_variables(t_point *ray, t_point *prev,
	float ray_angle, t_game *game)
{
	t_point	delta;

	delta.x = cos(deg_to_rad(ray_angle));
	delta.y = sin(deg_to_rad(ray_angle));
	prev->x = game->player_x;
	prev->y = game->player_y;
	ray->x = game->player_x + (delta.x * STEP);
	ray->y = game->player_y + (delta.y * STEP);
	while (!is_a_block(game, ray->x, ray->y))
	{
		prev->x = ray->x;
		prev->y = ray->y;
		ray->x += delta.x * STEP;
		ray->y += delta.y * STEP;
	}
}

void	draw_a_ray(t_game *game, float ray_angle, int ray_iteration)
{
	t_point	prev;
	t_point	ray;
	float	dist;

	set_the_variables(&ray, &prev, ray_angle, game);
	dist = (sqrtf((ray.x - game->player_x) * (ray.x - game->player_x)
				+ (ray.y - game->player_y)
				* (ray.y - game->player_y))) * cos(deg_to_rad(ray_angle)
			- deg_to_rad(game->player->angle));
	if ((int)prev.x > (int)ray.x)
		is_west(dist, 64 - ((ray.y - (int)ray.y) * 64), ray_iteration, game);
	else if ((int)prev.y > (int)ray.y)
		is_north(dist, (ray.x - (int)ray.x) * 64, ray_iteration, game);
	else if ((int)prev.x < (int)ray.x)
		is_east(dist, (ray.y - (int)ray.y) * 64, ray_iteration, game);
	else
		is_south(dist, 64 - ((ray.x - (int)ray.x) * 64), ray_iteration, game);
}

void	draw_rays(t_game *game)
{
	float	ray_angle;
	int		ray_iteration;

	ray_angle = -FOV / 2;
	ray_iteration = 0;
	while (ray_iteration < WIDTH)
	{
		draw_a_ray(game, ray_angle + game->player->angle, ray_iteration);
		ray_iteration++;
		ray_angle += (float)FOV / (float)WIDTH;
	}
}
