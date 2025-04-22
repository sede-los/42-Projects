/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:37:12 by isainz-r          #+#    #+#             */
/*   Updated: 2025/04/10 12:37:15 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

int	do_destroy_window(t_game *game)
{
	mlx_clear_window(game->mlx->mlx, game->mlx->mlx_win);
	mlx_destroy_image(game->mlx->mlx, game->mlx->img);
	mlx_destroy_window(game->mlx->mlx, game->mlx->mlx_win);
	if (game->info[0].img)
		mlx_destroy_image(game->mlx->mlx, game->info[0].img);
	if (game->info[1].img)
		mlx_destroy_image(game->mlx->mlx, game->info[1].img);
	if (game->info[2].img)
		mlx_destroy_image(game->mlx->mlx, game->info[2].img);
	if (game->info[3].img)
		mlx_destroy_image(game->mlx->mlx, game->info[3].img);
	mlx_destroy_display(game->mlx->mlx);
	free(game->mlx->mlx);
	free_structure(game);
	exit(0);
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == ESC)
		do_destroy_window(game);
	if (key == W)
		game->player->key_up = false;
	if (key == A)
		game->player->key_left = false;
	if (key == S)
		game->player->key_down = false;
	if (key == D)
		game->player->key_right = false;
	if (key == LEFT)
		game->player->left_rotate = false;
	if (key == RIGHT)
		game->player->right_rotate = false;
	return (0);
}

int	key_press(int key, t_game *game)
{
	if (key == ESC)
		do_destroy_window(game);
	if (key == W)
		game->player->key_up = true;
	if (key == A)
		game->player->key_left = true;
	if (key == S)
		game->player->key_down = true;
	if (key == D)
		game->player->key_right = true;
	if (key == LEFT)
		game->player->left_rotate = true;
	if (key == RIGHT)
		game->player->right_rotate = true;
	return (0);
}
