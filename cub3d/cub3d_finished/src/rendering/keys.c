/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:52:04 by isainz-r          #+#    #+#             */
/*   Updated: 2025/04/14 14:52:06 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

void	key_up(t_game *game, float speed)
{
	if (game->player_y + game->player->delta_y * speed <= 1.20
		|| game->player_y + game->player->delta_y * speed
		>= game->map_height - 1.20
		|| game->player_x + game->player->delta_x * speed <= 1.20
		|| game->player_x + game->player->delta_x * speed
		>= game->map_width - 1.20)
	{
		return ;
	}
	game->player_x += game->player->delta_x * speed;
	game->player_y += game->player->delta_y * speed;
}

void	key_down(t_game *game, float speed)
{
	if (game->player_y - game->player->delta_y * speed <= 1.20
		|| game->player_y - game->player->delta_y * speed
		>= game->map_height - 1.20
		|| game->player_x - game->player->delta_x * speed <= 1.20
		|| game->player_x - game->player->delta_x * speed
		>= game->map_width - 1.20)
	{
		return ;
	}
	game->player_x -= game->player->delta_x * speed;
	game->player_y -= game->player->delta_y * speed;
}

void	key_left(t_game *game, float speed)
{
	if (game->player_y - game->player->delta_x * speed <= 1.20
		|| game->player_y - game->player->delta_x * speed
		>= game->map_height - 1.20
		|| game->player_x + game->player->delta_y * speed <= 1.20
		|| game->player_x + game->player->delta_y * speed
		>= game->map_width - 1.20)
	{
		return ;
	}
	game->player_x += game->player->delta_y * speed;
	game->player_y -= game->player->delta_x * speed;
}

void	key_right(t_game *game, float speed)
{
	if (game->player_y + game->player->delta_x * speed <= 1.20
		|| game->player_y + game->player->delta_x * speed
		>= game->map_height - 1.20
		|| game->player_x - game->player->delta_y * speed <= 1.20
		|| game->player_x - game->player->delta_y * speed
		>= game->map_width - 1.20)
	{
		return ;
	}
	game->player_x -= game->player->delta_y * speed;
	game->player_y += game->player->delta_x * speed;
}
