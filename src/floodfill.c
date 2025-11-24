/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:43:09 by ryildiri          #+#    #+#             */
/*   Updated: 2025/11/24 21:27:31 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>
#include <unistd.h>

static char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;
	int		j;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = malloc(map->width + 1);
		if (!copy[i])
			return (NULL);
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

static void	flood_fill(char **map, int y, int x, t_map *orig)
{
	if (y < 0 || x < 0 || y >= orig->height || x >= orig->width)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, y + 1, x, orig);
	flood_fill(map, y - 1, x, orig);
	flood_fill(map, y, x + 1, orig);
	flood_fill(map, y, x - 1, orig);
}

static void	check_path_error(void)
{
	write(2, "Error\ncopy_map: NULL\n", 22);
	exit(1);
}

int	check_path(t_map *map)
{
	char	**copy;
	int		i;
	int		j;

	copy = copy_map(map);
	if (!copy)
		check_path_error();
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
