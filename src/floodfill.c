/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:43:09 by ryildiri          #+#    #+#             */
/*   Updated: 2025/11/28 22:23:55 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>
#include <unistd.h>

static char	**free_map(char **copy, int i)
{
	while (i - 1 >= 0)
	{
		free(copy[i - 1]);
		i--;
	}
	free(copy);
	return (NULL);
}

static char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;
	int		j;

	//copy = malloc(sizeof(char *) * (map->height + 1));
	copy = NULL;
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = malloc(map->width + 1);
		if (!copy[i])
			return (free_map(copy, i));
		j = 0;
		while (j < map->width)
		{
			copy[i][j] = map->data[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map_data, int y, int x, t_map *map)
{
	if (y < 0 || x < 0 || y >= map->height || x >= map->width)
		return ;
	if (map_data[y][x] == '1' || map_data[y][x] == 'V')
		return ;
	map_data[y][x] = 'V';
	flood_fill(map_data, y + 1, x, map);
	flood_fill(map_data, y - 1, x, map);
	flood_fill(map_data, y, x + 1, map);
	flood_fill(map_data, y, x - 1, map);
}

static void	check_path_error(t_map *map)
{
	write(2, "Error\ncopy_map: NULL\n", 21);
	free_all(map->data);
	exit (1);
}

int	check_path(t_map *map)
{
	char	**copy;
	int		i;
	int		j;

	copy = copy_map(map);
	if (!copy)
		check_path_error(map);
	flood_fill(copy, map->player_loc[0], map->player_loc[1], map);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
			{
				free_all(copy);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_all(copy);
	return (1);
}
