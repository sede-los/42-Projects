#ifndef GAME_H
#define GAME_H

#include "./mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

# define WIDTH 1280
# define HEIGHT 1280
# define BLOCK 64
# define DEBUG 0
#define MAP_WIDTH 16
#define MAP_HEIGHT 16

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

#ifndef M_PI
#   define M_PI 3.1415926535897932384626433832
#endif
# define PI M_PI
# define P2 PI / 2
# define P3 3 * PI / 2
# define DR 0.0174533

typedef struct s_texture
{
	void	*img;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
} t_texture;

typedef struct s_player
{
	float	x;
	float	y;
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

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;

	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_player	player;
	t_texture	textures[4];

	char		**map;
}				t_game;

void	init_player(t_player *player);
int		key_release(int keycode, t_player *player);
int		key_press(int keycode, t_player *player);
void	move_player(t_player *player);
float	deg_to_rad(int a);
int		fix_ang(int a);
#endif