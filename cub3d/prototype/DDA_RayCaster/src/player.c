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
	player->angle = 90;

	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;

	player->left_rotate = false;
	player->right_rotate = false;
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
	if(keycode == LEFT)
		player->left_rotate = true;
	if(keycode == RIGHT)
		player->right_rotate = true;
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
	if(keycode == LEFT)
		player->left_rotate = false;
	if(keycode == RIGHT)
		player->right_rotate = false;
	return (0);
}

void move_player(t_player *player)
{
	int 	speed = 3;
	int		rotation_speed = 2;
	player->delta_x=cos(deg_to_rad(player->angle));
	player->delta_y=-sin(deg_to_rad(player->angle));

	if(player->left_rotate)
	{
	player->angle += rotation_speed;
	player->angle = fix_ang(player->angle);
	player->delta_x = cos(deg_to_rad(player->angle));
	player->delta_y = -sin(deg_to_rad(player->angle));
	}
	if(player->right_rotate)
	{
		player->angle -= rotation_speed;
		player->angle = fix_ang(player->angle);
		player->delta_x = cos(deg_to_rad(player->angle));
		player->delta_y = -sin(deg_to_rad(player->angle));
	} 
	if (player->key_up)
    {
        player->x += player->delta_x * speed;
        player->y += player->delta_y * speed;
    }
    if (player->key_down)
    {
        player->x -= player->delta_x * speed;
        player->y -= player->delta_y * speed;
    }
    if (player->key_left)
    {
        player->x += player->delta_y * speed;
        player->y -= player->delta_x * speed;
    }
    if (player->key_right)
    {
        player->x -= player->delta_y * speed;
        player->y += player->delta_x * speed;
    }
}