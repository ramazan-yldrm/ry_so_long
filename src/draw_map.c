#include "../includes/so_long.h"
#include "../mlx/mlx.h"


#include <unistd.h>
#include <stdlib.h>
void load_textures(t_game *game)
{
    int width;
    int height;

    game->wall_texture = mlx_xpm_file_to_image(game->init, "textures/wall.xpm", &width, &height);
    game->floor_texture = mlx_xpm_file_to_image(game->init, "textures/floor.xpm", &width, &height);
    game->player_texture = mlx_xpm_file_to_image(game->init, "textures/player.xpm", &width, &height);
    game->coin_texture = mlx_xpm_file_to_image(game->init, "textures/coin.xpm", &width, &height);
    game->exit_texture = mlx_xpm_file_to_image(game->init, "textures/exit.xpm", &width, &height);
}

void draw_map(t_game *game)
{
    void *img;
    int  i;
    int  j;

    i = 0;
    while (game->map.data[i])
    {
        j = 0;
        while (game->map.data[i][j] != '\0')
        {
            if (game->map.data[i][j] == '1')
                img = game->wall_texture;
            else if (game->map.data[i][j] == '0')
                img = game->floor_texture;
            else if (game->map.data[i][j] == 'P')
                img = game->player_texture;
            else if (game->map.data[i][j] == 'C')
                img = game->coin_texture;
            else if (game->map.data[i][j] == 'E')
                img = game->exit_texture;
            mlx_put_image_to_window(game->init, game->win, img, j * 64, i * 64);
            j++;
        }
        i++;
    }
}
