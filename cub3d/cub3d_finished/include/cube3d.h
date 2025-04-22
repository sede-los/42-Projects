/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:06:10 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/12 10:06:13 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# include <stdint.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h> //printf, perror
# include <stdlib.h> //malloc, free, exit
# include <unistd.h> //close, read, write
# include <fcntl.h> //open
# include <string.h> //strerror
# include <sys/time.h> //gettimeofday
# include <math.h>

#define WIDTH 1280
#define HEIGHT 1200
#define PI 3.1415926535897932384626433832
#define FOV 60
#define STEP 0.01

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

#define W 119
#define A 97
#define S 115
#define D 100
#define LEFT 65361
#define RIGHT 65363
#define ESC 65307

typedef struct s_point
{
	float	x;
	float	y;
}			t_point;


typedef struct s_info
{
	void	*img;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
} t_info;

typedef struct s_player
{
	float	angle;
	float	delta_x;
	float	delta_y;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;

	bool	left_rotate;
	bool	right_rotate;
}				t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}			t_mlx;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		floor[4];
	int		celing[4];
}			t_textures;

typedef struct s_game
{
	char		*is_map;
	char		*is_texture;
	char		**map;
	int			map_width;
	int			map_height;
	char		player_dir;
	float		player_x;
	float		player_y;
	t_textures	*textures;
	t_mlx		*mlx;
	t_player	*player;
	t_info		info[4];
}				t_game;

//MAIN
int		errors(char	*str);

//PARSE
int		parse(t_game *game, char *argv);
int		check_cub(char *argv);
int		open_save_all(char *argv, t_game *game, int temp);
void	free_matrix(char **matrix);
int		check_textures(t_game *game);
int		check_map(t_game *game);
int		rectangular_map(t_game *game);
int		check_rectangle(t_game *game);
void	free_structure(t_game *game);
int	check_colors(char **split_line, t_game *game);

//RENDER
int		render_map(t_game *game);
int		do_destroy_window(t_game *game);
int		key_release(int key, t_game *game);
int		key_press(int key, t_game *game);
int	move_player(t_game *game);
float	deg_to_rad(float angle);
void	draw_rays(t_game *game);
void	put_pixel(int x, int y, int color, t_game *game);
void	key_up(t_game *game, float speed);
void	key_down(t_game *game, float speed);
void	key_left(t_game *game, float speed);
void	key_right(t_game *game, float speed);
void	is_north(float dist, float plane_x,	int ray_iteration, t_game *game);
void	is_south(float dist, float plane_x,	int ray_iteration, t_game *game);
void	is_east(float dist, float plane_x, int ray_iteration, t_game *game);
void	is_west(float dist, float plane_x, int ray_iteration, t_game *game);
void	put_pixel(int x, int y, int color, t_game *game);

#endif