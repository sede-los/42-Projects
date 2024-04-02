/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:29:13 by sede-los          #+#    #+#             */
/*   Updated: 2024/04/02 21:17:58 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		ft_error(0);
	vars.map_path = argv[1];
	check_extension(vars.map_path);
	check_map_size(&vars);
	if (vars.win_width > 35 || vars.win_height > 35)
		ft_error(8);
	malloc_map(&vars);
	check_border(&vars);
	vars.player_coins = 0;
	vars.map_coins = 0;
	vars.map_player = 0;
	vars.map_exit = 0;
	vars.steps = 0;
	count_map(&vars);
	check_route(&vars);
	initialize_game(&vars);
	return (0);
}
