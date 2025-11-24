#include "../includes/so_long.h"
#include <stdlib.h>
#include <stdio.h>

static void finish_game()
{
    exit(0);
}

void move_up(t_game *game)
{
    int x;
    int y; 

    y = game->map.player_loc[0]; 
    x = game->map.player_loc[1];
    if (y - 1 < 0 || game->map.data[y - 1][x] == '1')
        return;
    game->map.data[y][x] = '0';
    y -= 1;
    if (game->map.data[y][x] == 'C')
        game->map.coin--;
    if (game->map.coin == 0 && game->map.data[y][x] == 'E')
        finish_game();
    game->map.player_loc[0] = y;
    game->map.data[y][x] = 'P';
    game->map.step++;
    printf("step:%d\n", game->map.step);
    draw_map(game);
}

void move_down(t_game *game)
{
    int x;
    int y; 

    y = game->map.player_loc[0]; 
    x = game->map.player_loc[1];
    if (y + 1 >= game->map.height || game->map.data[y + 1][x] == '1')
        return;
    game->map.data[y][x] = '0';
    y += 1;
    if (game->map.data[y][x] == 'C')
        game->map.coin--;
    if (game->map.coin == 0 && game->map.data[y][x] == 'E')
        finish_game();
    game->map.player_loc[0] = y;
    game->map.data[y][x] = 'P';
    game->map.step++;
    printf("step:%d\n", game->map.step);
    draw_map(game);
}

void move_left(t_game *game)
{
    int x;
    int y; 

    y = game->map.player_loc[0]; 
    x = game->map.player_loc[1];
    if (x - 1 < 0 || game->map.data[y][x - 1] == '1')
        return;
    game->map.data[y][x] = '0';
    x -= 1;
    if (game->map.data[y][x] == 'C')
        game->map.coin--;
    if (game->map.coin == 0 && game->map.data[y][x] == 'E')
        finish_game();
    game->map.player_loc[1] = x;
    game->map.data[y][x] = 'P';
    game->map.step++;
    printf("step:%d\n", game->map.step);
    draw_map(game);
}

void move_right(t_game *game)
{
    int x;
    int y; 

    y = game->map.player_loc[0]; 
    x = game->map.player_loc[1];
    if (x + 1 >= game->map.width || game->map.data[y][x + 1] == '1')
        return;
    game->map.data[y][x] = '0';
    x += 1;
    if (game->map.data[y][x] == 'C')
        game->map.coin--;
    if (game->map.coin == 0 && game->map.data[y][x] == 'E')
        finish_game();    
    game->map.player_loc[1] = x;
    game->map.data[y][x] = 'P';
    game->map.step++;
    printf("step:%d\n", game->map.step);
    draw_map(game);
}

int catch_key(int keycode, t_game *game)
{
    if (keycode == 65307)
        finish_game();
    else if (keycode == 'w')
        move_up(game);
    else if (keycode == 'a')
        move_left(game);
    else if (keycode == 's')
        move_down(game);
    else if (keycode == 'd')
        move_right(game);
    return (0);
}