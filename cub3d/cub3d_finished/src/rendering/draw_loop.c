/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:39:56 by isainz-r          #+#    #+#             */
/*   Updated: 2025/04/10 12:39:58 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

float	deg_to_rad(float angle)
{
	return (angle * PI / 180.0);
}

float	fix_ang(float angle)
{
	if (angle > 359)
		angle -= 360;
	if (angle < 0)
		angle += 360;
	return (angle);
}

int	argb_to_int(int a, int r, int g, int b)
{
	return ((a << 24) | (r << 16) | (g << 8) | b);
}

void	clear_image(t_game *game)
{
	int	y;
	int	x;
	int	celing;
	int	floor;

	floor = (int)((255 << 24) | (game->textures->floor[0] << 16)
			| (game->textures->floor[1] << 8) | game->textures->floor[2]);
	celing = (int)((255 << 24) | (game->textures->celing[0] << 16)
			| (game->textures->celing[1] << 8) | game->textures->celing[2]);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < 600)
				put_pixel(x, y, celing, game);
			else
				put_pixel(x, y, floor, game);
			x++;
		}
		y++;
	}
}

int	move_player(t_game *game)
{
	float	speed;
	int		rotation_speed;

	speed = 0.2;
	rotation_speed = 4;
	if (game->player->right_rotate)
		game->player->angle += rotation_speed;
	if (game->player->left_rotate)
		game->player->angle -= rotation_speed;
	game->player->angle = fix_ang(game->player->angle);
	game->player->delta_x = cos(deg_to_rad(game->player->angle));
	game->player->delta_y = sin(deg_to_rad(game->player->angle));
	if (game->player->key_up)
		key_up(game, speed);
	if (game->player->key_down)
		key_down(game, speed);
	if (game->player->key_left)
		key_left(game, speed);
	if (game->player->key_right)
		key_right(game, speed);
	clear_image(game);
	draw_rays(game);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->mlx_win,
		game->mlx->img, 0, 0);
	return (0);
}
