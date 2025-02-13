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

void put_pixel(int x, int y, int color, t_game *game)
{
    if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return;
    
    int index = y * game->size_line + x * game->bpp / 8;
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

void init_game(t_game *game)
{
    init_player(&game->player);
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "RayCasting");
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int draw_loop(t_game *game)
{
    t_player *player;

    player = &game->player;
    move_player(player);
    clear_image(game);
    draw_square(player->x, player->y, 10, 0x00FF00, game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
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
