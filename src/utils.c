#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

int close_game(t_game *game)
{
    destroy_textures(game);

    if (game->win)
        mlx_destroy_window(game->init, game->win);

    if (game->init)
        mlx_destroy_display(game->init);

    free(game->init);  // Linux MLX için gereklidir

    free_all(game->map.data);

    exit(0);
}

void free_all(char **str)
{
    int i;

    i = 0;
    while(str[i] != NULL)
    {
        free(str[i]);
        i++;
    }
	free(str);
}