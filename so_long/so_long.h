/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-los <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:47:20 by sede-los          #+#    #+#             */
/*   Updated: 2024/03/31 04:30:56 by sede-los         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include <mlx.h>

# define SIZE 64

typedef enum e_key
{
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_ESC = 53,
}	t_key;

typedef struct s_xpm
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}				t_xpm;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	*map_path;
	char	**matrix;
	int		win_width;
	int		win_height;
	int		map_coins;
	int		map_player;
	int		map_exit;
	int		player_coins;
	int		steps;
	int		p_x;
	int		p_y;
	t_xpm	image_0;
	t_xpm	image_1;
	t_xpm	image_c;
	t_xpm	image_p;
	t_xpm	image_e;
}				t_vars;

void	check_map_size(t_vars *vars);
void	malloc_map(t_vars *vars);
void	ft_error(int error);
void	ft_error_free(int error, t_vars *vars);
void	check_char(char c);
void	initialize_game(t_vars *vars);
void	initialize_images(t_vars *vars);
void	print_matrix(t_vars *vars);
void	print_images(t_vars *vars, char image, int i, int j);
int		key_hook(int k, t_vars *vars);
void	exit_game(t_vars *vars);
void	move_player(t_vars *vars, int keycode);
void	count_map(t_vars *vars);
void	player_up(t_vars *vars);
void	player_down(t_vars *vars);
void	player_left(t_vars *vars);
void	player_right(t_vars *vars);
void	check_extension(char *map_name);
void	check_route(t_vars *vars);
char	**duplicate_matrix(t_vars *vars);
void	free_matrix(char **matrix, t_vars *vars);
void	flood_fill(char **matrix, int pos_y, int pos_x);
void	check_border(t_vars *vars);
void	check_vertical(t_vars *vars);
void	check_horizontal(t_vars *vars);

#endif
