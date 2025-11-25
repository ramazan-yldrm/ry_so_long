/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:27:41 by ryildiri          #+#    #+#             */
/*   Updated: 2025/11/25 09:54:32 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>
#include <unistd.h>

static int	is_map_square(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->data[i] != NULL)
	{
		j = 0;
		while (map->data[i][j] != '\0')
			j++;
		if (j != map->width)
			return (0);
		i++;
	}
	return (1);
}

static int	is_map_close(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->data[i])
	{
		j = 0;
		if (map->width != 0)
		{
			while (map->data[i][j])
			{
				if (map->data[0][j] != '1')
					return (0);
				if (map->data[i][0] != '1')
					return (0);
				if (map->data[map->height - 1][j] != '1')
					return (0);
				if (map->data[i][map->width - 1] != '1')
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

void	check_map(t_map *map)
{
	if (is_map_square(map) == 0)
		map_error("Error\nMap not square\n", map->data);
	if (is_map_close(map) == 0)
		map_error("Error\nMap not close\n", map->data);
	if (map->player != 1)
		map_error("Error\nOnly one player\n", map->data);
	if (map->exit != 1)
		map_error("Error\nOnly one exit\n", map->data);
	if (map->coin < 1)
		map_error("Error\nThere must be at least one token\n", map->data);
	if (!check_path(map))
		map_error("Error\nMap is not playable\n", map->data);
}
