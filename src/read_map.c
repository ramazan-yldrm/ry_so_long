/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:52:40 by ryildiri          #+#    #+#             */
/*   Updated: 2025/11/25 18:56:30 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	sizeof_map(t_map *map)
{
	char	*line;
	int		fd;

	fd = open(map->path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nmap_size/open: -1\n", 24);
		free(map->path);
		exit(1);
	}
	map->width = 0;
	map->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (map->width == 0)
		{
			while (line[map->width] && line[map->width] != '\n')
				map->width++;
		}
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static void	read_map_data_errors(int status, int closeble, char *path)
{
	if (status == 0)
	{
		write(2, "Error\nread_map/open : -1\n", 25);
		free(path);
	}
	else
	{
		write(2, "Error\nmap_read/malloc/map->data: NULL", 37);
		free(path);
		close(closeble);
	}
	exit(1);
}

void	read_map_data(t_map *map)
{
	int	fd;
	int	i;
	int	j;

	fd = open(map->path, O_RDONLY);
	if (fd == -1)
		read_map_data_errors(0, 0, map->path);
	map->data = malloc(sizeof(char *) * (map->height + 1));
	if (!map->data)
		read_map_data_errors(1, fd, map->path);
	i = 0;
	map->data[i] = get_next_line(fd);
	while (map->data[i])
	{
		j = 0;
		while ((map->data[i][j] != '\0'))
		{
			if (map->data[i][j] == '\n')
				map->data[i][j] = '\0';
			j++;
		}
		map->data[++i] = get_next_line(fd);
	}
	free(map->path);
	close(fd);
}

static	void	save_player_loc(t_map *map, int x, int y)
{
	map->player_loc[0] = y;
	map->player_loc[1] = x;
	map->player++;
}

void	read_map_args(t_map *map)
{
	int	i;
	int	j;

	map->player = 0;
	map->exit = 0;
	map->coin = 0;
	i = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (map->data[i][j] == 'P')
				save_player_loc(map, j, i);
			else if (map->data[i][j] == 'C')
				map->coin++;
			else if (map->data[i][j] == 'E')
				map->exit++;
			else if (map->data[i][j] != '0' && map->data[i][j] != '1')
				map_error("Error\nUndefined map args\n", map->data);
			j++;
		}
		i++;
	}
}
