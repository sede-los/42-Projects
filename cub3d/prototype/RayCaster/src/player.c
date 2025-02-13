/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 07:05:22 by sergio            #+#    #+#             */
/*   Updated: 2025/02/13 07:05:28 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;

	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
}

int key_press(int keycode, t_player *player)
{
	if(keycode == W)
		player->key_up = true;
	if(keycode == S)
		player->key_down = true;
	if(keycode == D)
		player->key_right = true;
	if(keycode == A)
		player->key_left = true;
	return (0);
}

int key_release(int keycode, t_player *player)
{
	if(keycode == W)
		player->key_up = false;
	if(keycode == S)
		player->key_down = false;
	if(keycode == D)
		player->key_right = false;
	if(keycode == A)
		player->key_left = false;
	return (0);
}

void move_player(t_player *player)
{
	int speed = 3;

	if(player->key_up)
		player->y -= speed;
	if(player->key_down)
		player->y += speed;
	if(player->key_left)
		player->x -= speed;
	if(player->key_right)
		player->x += speed;
}