/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:45:17 by ryildiri          #+#    #+#             */
/*   Updated: 2025/11/25 01:25:01 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static void	check_args_error(char *str, char *path)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	free(path);
	exit(1);
}

static void	check_args(t_map *map, char *av)
{
	char	*path;
	int		fd;
	int		len;

	path = ft_strdup(av);
	if (!path)
		check_args_error("Error\narg_check/ft_strjoin: NULL\n", NULL);
	len = ft_strlen(av);
	if (len < 5 || ft_strncmp(av + len - 4, ".ber", 4) != 0)
		check_args_error("Error\ninvalid file format <maps/file.ber>\n", path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		check_args_error("Error\nfile not found\n", path);
	map->path = path;
	close(fd);
}

static void	countinue(t_game *game)
{
	game->map.step = 0;
	game->init = mlx_init();
	if (!game->init)
	{
		write(2, "Error\nMLX initialization failed\n", 32);
		free_all(game->map.data);
		exit(1);
	}
	game->win = mlx_new_window(\
		game->init, game->map.width * 64, game->map.height * 64, "so_long");
	if (!game->win)
	{
		write(2, "Error\nMLX window creation failed\n", 34);
		mlx_destroy_display(game->init);
		free(game->init);
		free_all(game->map.data);
		exit(1);
	}
	load_textures(game);
	draw_map(game);
	mlx_hook(game->win, 2, 1L << 0, catch_key, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->init);
}

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
	{
		write(2, "Error\n./so_long <maps/example.ber>\n", 35);
		exit(1);
	}
	check_args(&game.map, av[1]);
	sizeof_map(&game.map);
	read_map_data(&game.map);
	read_map_args(&game.map);
	check_map(&game.map);
	countinue(&game);
}
