/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:40:37 by isainz-r          #+#    #+#             */
/*   Updated: 2025/03/26 09:40:39 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

void	set_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->info[i].data = mlx_get_data_addr(
				game->info[i].img, &game->info[i].bpp,
				&game->info[i].size_line, &game->info[i].endian);
		i++;
	}
}

int	load_images(t_game *game)
{
	game->info[0].img = mlx_xpm_file_to_image(game->mlx->mlx,
			game->textures->north, &game->info[0].width,
			&game->info[0].height);
	game->info[1].img = mlx_xpm_file_to_image(game->mlx->mlx,
			game->textures->south, &game->info[1].width,
			&game->info[1].height);
	game->info[2].img = mlx_xpm_file_to_image(game->mlx->mlx,
			game->textures->east, &game->info[2].width,
			&game->info[2].height);
	game->info[3].img = mlx_xpm_file_to_image(game->mlx->mlx,
			game->textures->west, &game->info[3].width,
			&game->info[3].height);
	if (!game->info[0].img || !game->info[1].img
		|| !game->info[2].img || !game->info[3].img)
	{
		return (1);
	}
	set_images(game);
	return (0);
}

int	render_map(t_game *game)
{
	game->mlx->mlx = mlx_init();
	if (!game->mlx->mlx)
		return (errors("Problem with the MLX\n"));
	game->mlx->mlx_win = mlx_new_window(game->mlx->mlx, WIDTH, HEIGHT, "CUB3D");
	if (!game->mlx->mlx_win)
		return (free(game->mlx->mlx), errors("Problem with the MLX\n"));
	game->mlx->img = mlx_new_image(game->mlx->mlx, WIDTH, HEIGHT);
	game->mlx->data = mlx_get_data_addr(game->mlx->img, &game->mlx->bpp,
			&game->mlx->size_line, &game->mlx->endian);
	mlx_hook(game->mlx->mlx_win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx->mlx_win, 3, 1L << 1, key_release, game);
	mlx_hook(game->mlx->mlx_win, 17, 1L << 17, do_destroy_window, game);
	if (load_images(game) == 1)
		return (errors("Problem loading the images\n"));
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->mlx_win,
		game->mlx->img, 0, 0);
	mlx_loop_hook(game->mlx->mlx, move_player, game);
	mlx_loop(game->mlx->mlx);
	return (0);
}
