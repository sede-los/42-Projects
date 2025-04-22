/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:06:36 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/12 10:06:37 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

void	set_player_angle(t_game *game)
{
	if (game->player_dir == 'N')
		game->player->angle = 90;
	if (game->player_dir == 'S')
		game->player->angle = 270;
	if (game->player_dir == 'E')
		game->player->angle = 0;
	if (game->player_dir == 'W')
		game->player->angle = 180;
}

int	parse(t_game *game, char *argv)
{
	if (check_cub(argv) == 1)
		return (1);
	if (open_save_all(argv, game, 0) == 1)
		return (1);
	if (check_textures(game) == 1)
		return (1);
	if (check_map(game) == 1)
		return (1);
	if (rectangular_map(game) == 1)
		return (1);
	if (check_rectangle(game) == 1)
		return (1);
	set_player_angle(game);
	return (0);
}
