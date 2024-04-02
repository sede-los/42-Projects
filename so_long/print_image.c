/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:26:07 by sede-los          #+#    #+#             */
/*   Updated: 2024/03/22 16:59:16 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_images(t_vars *vars, char image, int i, int j)
{
	if (image == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image_0.img,
			j * SIZE, i * SIZE);
	else if (image == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image_1.img,
			j * SIZE, i * SIZE);
	else if (image == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image_c.img,
			j * SIZE, i * SIZE);
	else if (image == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image_e.img,
			j * SIZE, i * SIZE);
	else if (image == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image_p.img,
			j * SIZE, i * SIZE);
}
