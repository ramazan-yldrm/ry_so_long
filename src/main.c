#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

static void check_args(t_map *map, char *av)
{
    char *path;
    int fd;
    int len;

    path = ft_strjoin("maps/", av);
    if (!path)
    {
        write(2, "Error\narg_check/ft_strjoin: NULL\n", 33);
        exit(1);
    }
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        write(2, "Error\nfile not found\n", 21);
        free(path);
        exit(1);
    }
    len = ft_strlen(av);
    if (len < 4 || ft_strncmp(av + len - 4, ".ber", 4) != 0)
    {
        write(2, "Error\ninvalid file format <file.ber>\n", 37);
        exit(1);
    }
    map->path = path;
    close(fd);
}

static void start(t_game *game)
{
    sizeof_map(&game->map);
    read_map_data(&game->map);
    read_map_args(&game->map);
}

int close_game(t_game *game)
{
    (void)game;
    exit(0);
    return (0);
}

static void countinue(t_game *game)
{
    int width;
    int height;

    width = game->map.width * 64;
    height = game->map.height * 64;
    if (width > 1920 || height > 1080)
    {
        width = 1920;
        height = 1080;
    }
    game->map.step = 0;
    game->init = mlx_init();
    game->win = mlx_new_window(game->init, width, height, "so_long");
    mlx_hook(game->win, 2, 1L<<0, catch_key, game);
    mlx_hook(game->win, 17, 0, close_game, game);
    load_textures(game);
    draw_map(game);
    mlx_loop(game->init);
}

int main(int ac, char *av[])
{
    t_game game;
    
    if (ac != 2)
    {
        write(2, "Error\n./so_long <example.ber>\n", 30);
        exit(1);
    }
    check_args(&game.map, av[1]);
    start(&game);
    if (check_map(&game.map) == 0)
        return (1);
    countinue(&game);
}
