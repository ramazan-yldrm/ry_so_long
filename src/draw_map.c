/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:38:11 by ryildiri          #+#    #+#             */
/*   Updated: 2025/11/26 00:38:37 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	destroy_textures(t_game *game)
{
	if (game->wall_texture)
		mlx_destroy_image(game->init, game->wall_texture);
	if (game->floor_texture)
		mlx_destroy_image(game->init, game->floor_texture);
	if (game->player_texture)
		mlx_destroy_image(game->init, game->player_texture);
	if (game->coin_texture)
		mlx_destroy_image(game->init, game->coin_texture);
	if (game->exit_texture)
		mlx_destroy_image(game->init, game->exit_texture);
}

static int	check_texture(void)
{
	int	fd;

	fd = open("textures/coin.xpm", O_RDONLY);
	if (fd == -1)
		return (0);
	close (fd);
	fd = open("textures/exit.xpm", O_RDONLY);
	if (fd == -1)
		return (0);
	close (fd);
	fd = open("textures/floor.xpm", O_RDONLY);
	if (fd == -1)
		return (0);
	close (fd);
	fd = open("textures/player.xpm", O_RDONLY);
	if (fd == -1)
		return (0);
	close (fd);
	fd = open("textures/wall.xpm", O_RDONLY);
	if (fd == -1)
		return (0);
	close (fd);
	return (1);
}

void	load_textures(t_game *game)
{
	int	width;
	int	height;

	if (check_texture() == 0)
	{
		write(2, "Error\nTexture not found\n", 24);
		mlx_destroy_display(game->init);
		free(game->init);
		free_all(game->map.data);
		exit(1);
	}
	game->wall_texture = mlx_xpm_file_to_image(\
		game->init, "textures/wall.xpm", &width, &height);
	game->floor_texture = mlx_xpm_file_to_image(\
		game->init, "textures/floor.xpm", &width, &height);
	game->player_texture = mlx_xpm_file_to_image(\
		game->init, "textures/player.xpm", &width, &height);
	game->coin_texture = mlx_xpm_file_to_image(\
		game->init, "textures/coin.xpm", &width, &height);
	game->exit_texture = mlx_xpm_file_to_image(\
		game->init, "textures/exit.xpm", &width, &height);
}

void	draw_map(t_game *game)
{
	void	*img;
	int		i;
	int		j;

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
