/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 05:26:24 by sergio            #+#    #+#             */
/*   Updated: 2025/02/13 05:26:27 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

float deg_to_rad(int a)
{
    return (a * PI / 180.0);
}

int fix_ang(int a)
{
     if(a > 359)
        a -= 360;
     if(a < 0)
        a += 360;
    return (a);
}

float distance(float x, float y)
{
    return sqrt(x * x + y * y);
}

float fixed_dist(float x1, float y1, float x2, float y2, t_game *game)
{
    float delta_x = x2 - x1;
    float delta_y = y2 - y1;
    float angle = atan2(delta_y, delta_x) - game->player.angle;
    float fix_dist = distance(delta_x, delta_y) * cos(angle);
    return fix_dist;
}

void put_pixel(int x, int y, int color, t_game *game)
{
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    int index = (y * game->size_line) + (x * (game->bpp / 8));

    if (index < 0 || index >= (HEIGHT * game->size_line))
        return;
    game->data[index] = color & 0xFF;
    game->data[index + 1] = (color >> 8) & 0xFF;
    game->data[index + 2] = (color >> 16) & 0xFF;
}

void draw_square(int x, int y, int size, int color, t_game *game)
{
    int i;

    i = -1;
    while(++i < size)
        put_pixel(x + i, y, color, game);
    i = -1;
    while(++i < size)
        put_pixel(x, y + i, color, game);
    i = -1;
    while(++i < size)
        put_pixel(x + size, y + i, color, game);
    i = -1;
    while(++i < size)
        put_pixel(x + i, y + size, color, game);
    i = -1;
}

void draw_map(t_game *game)
{
    char    **map;
    int     color;
    int     y;
    int     x;

    map = game->map;
    color = 0x0000FF;
    y = 0;
    while(map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if(map[y][x] == '1' || map[y][x] == ' ')
                draw_square(x * BLOCK, y * BLOCK, BLOCK, color, game);
            x++;
        }
        y++;
    }
}

void clear_image(t_game *game)
{
    int y;
    int x;

    y = 0;
    while(y < HEIGHT)
    {
        x = 0;
        while(x < WIDTH)
        {
            put_pixel(x, y, 0, game);
            x++;
        }
        y++;
    }
}

int touch(float rx, float ry, t_game *game)
{
    int map_x, map_y;

    map_x = (int)(rx / BLOCK);
    map_y = (int)(ry / BLOCK);

    if (map_x < 0 || map_x >= MAP_WIDTH || map_y < 0 || map_y >= MAP_HEIGHT)
        return 1;

    if (game->map[map_y] == NULL || game->map[map_y][map_x] == '\0')
        return 1;

    return (game->map[map_y][map_x] == '1');
}

char **get_map(void)
{
    char *raw_map[] = {
        "1111111111111111",
        "1000000000000001",
        "1000100000000001",
        "1000000000100001",
        "1000100000000001",
        "1000000000000001",
        "1000100000000001",
        "1010000000000001",
        "1000000000000001",
        "1000000000000001",
        "1000000000000001",
        "1000000011000001",
        "1000000000000001",
        "1000100000000001",
        "1000000000000001",
        "1111111111111111",
        NULL
    };

    int rows = 16;
    char **map = malloc(sizeof(char *) * (rows + 1));
    if (!map) return NULL;

    for (int i = 0; i < rows; i++)
    {
        map[i] = strdup(raw_map[i]);
        if (!map[i])
        {
            while (i > 0) free(map[--i]);
            free(map);
            return NULL;
        }
    }
    map[rows] = NULL;

    return map;
}


void load_textures(t_game *game)
{
	int i;
	char *texture_paths[4] = 
	{
		"textures/wall_north.xpm",
		"textures/wall_south.xpm",
		"textures/wall_east.xpm",
		"textures/wall_west.xpm"
	};
	i = 0;
	while(i < 4)
	{
		game->textures[i].img = mlx_xpm_file_to_image(game->mlx, texture_paths[i], &game->textures[i].width, &game->textures[i].height);
		if(!game->textures[i].img)
		{
			printf("Error loading texture: %s\n", texture_paths[i]);
			exit(1);
		}
		game->textures[i].data = mlx_get_data_addr(game->textures[i].img, &game->textures[i].bpp, &game->textures[i].size_line, &game->textures[i].endian);
		i++;
	}
}

void draw_line(int x0, int y0, int x1, int y1, int color, t_game *game)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    
    while (x0 != x1 || y0 != y1)
    {
        put_pixel(x0, y0, color, game);
        int e2 = 2 * err;
        
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
    put_pixel(x1, y1, color, game);
}

void draw_rays(t_player *player, t_game *game)
{
    int     r;
    int     dof;
    float   ra;
    float   ry;
    float   rx;
    float   xo;
    float   yo;
    float   disV;
    float   disH;
    float   vx;
    float   vy;

    ra = fix_ang(player->angle + 30);//ray set back 30 degrees
    r = 0;
    while (r < 60)
    {
        //---Vertical--- 
        dof = 0;
        disV = 100000;
        float Tan = tan(deg_to_rad(ra));
        if(cos(deg_to_rad(ra)) > 0.001)//looking left
        {
            rx = (((int)player->x >> 6) <<6 ) + 64;
            ry = (player->x - rx) * Tan + player->y;
            xo = 64;
            yo = -xo * Tan;
        }
        else if(cos(deg_to_rad(ra)) < -0.001)//looking right
        {
            rx = (((int)player->x >> 6) << 6) -0.0001;
            ry = (player->x - rx) * Tan + player->y;
            xo = -64;
            yo = -xo * Tan;
        }
        else//looking up or down. no hit
        {
            rx = player->x;
            ry = player->y;
            dof = 8;
        }

        while (dof < 16)
        {
            if (rx < 0 || ry < 0 || rx / BLOCK >= MAP_WIDTH || ry / BLOCK >= MAP_HEIGHT)
                break;
            if (touch(rx, ry, game))
            {
                dof=16;
                disV=cos(deg_to_rad(ra)) * (rx - player->x) - sin(deg_to_rad(ra)) * (ry-player->y);
            }
            else
            {
                rx += xo;
                ry += yo;
                dof++;
            }
        }
        vx = rx;
        vy = ry;

        //---Horizontal---
        dof = 0;
        disH = 100000;
        Tan = 1.0/Tan;
        if(sin(deg_to_rad(ra)) > 0.001)//looking up
        {
            ry = (((int)player->y>>6)<<6) -0.0001;
            rx = (player->y-ry) * Tan + player->x;
            yo = -64;
            xo = -yo * Tan;
        }
        else if(sin(deg_to_rad(ra)) < -0.001)//looking down
        {
            ry = (((int)player->y >> 6) << 6)+64;
            rx = (player->y-ry) * Tan + player->x;
            yo = 64;
            xo = -yo * Tan;
        }
        else//looking straight left or right
        {
            rx = player->x;
            ry = player->y;
            dof = 8;
        }
        while (dof < 16)
        {
            if (rx < 0 || ry < 0 || rx / BLOCK >= MAP_WIDTH || ry / BLOCK >= MAP_HEIGHT)
                break;
            if (touch(rx, ry, game))
            {
                dof=16;
                disH=cos(deg_to_rad(ra)) * (rx-player->x)-sin(deg_to_rad(ra)) * (ry-player->y);
            }
            else
            {
                rx += xo;
                ry += yo;
                dof++;
            }
        }
        if(disV<disH)//horizontal hit first
        {
            rx = vx;
            ry = vy;
            disH = disV;
        }
        draw_line(player->x, player->y, rx, ry, 0xFF0000, game);
        ra=fix_ang(ra - 1);
        r++;
    }
}

void init_game(t_game *game)
{
    init_player(&game->player);
    game->map = get_map();
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "DDA-RayCasting");
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
	//load_textures(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int draw_loop(t_game *game)
{
    t_player *player;

    player = &game->player;
    move_player(player);
    clear_image(game);
    draw_square(player->x, player->y, 10, 0x00FF00, game);
    draw_map(game);
    draw_rays(player, game);

    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

int main(void)
{
    t_game game;

    init_game(&game);
    mlx_hook(game.win, 2, 1L<<0, key_press, &game.player);
    mlx_hook(game.win, 3, 1L<<1, key_release, &game.player);
    mlx_loop_hook(game.mlx, draw_loop, &game);
    mlx_loop(game.mlx);

    return (0);
}
