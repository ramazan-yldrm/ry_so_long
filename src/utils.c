/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:01:46 by ryildiri          #+#    #+#             */
/*   Updated: 2025/11/25 18:56:47 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include <stdlib.h>
#include <unistd.h>

int	close_game(t_game *game)
{
	destroy_textures(game);
	if (game->win)
		mlx_destroy_window(game->init, game->win);
	if (game->init)
	{
		mlx_destroy_display(game->init);
		free(game->init);
	}
	free_all(game->map.data);
	exit(0);
}

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	map_error(char *str, char **map_data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	free_all(map_data);
	exit(1);
}
