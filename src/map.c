#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void	sizeof_map(t_map *map)
{
	char	*line;
	int		fd;

	fd = open(map->path_ptr, O_RDONLY);
	if (fd == -1)
	{
		printf("exit1");
		exit(1);
	}
	map->heigth = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		//map->width yapısını daha sonra geliştirebilirim mesela map 4gen mi diye kontrol edebilir
		map->width = 0;
		while (line[map->width])
			map->width++;
		map->heigth++;
	}
	map->width--;
}

void	read_map(t_map *map)
{
	int		fd;
	int		i;
	int		j;

	fd = open(map->path_ptr, O_RDONLY);
	if (fd == -1)
	{
		printf("exit2");
		exit(1);
	}
	map->map_2ptr = malloc(sizeof(char *) * (100));
	i = 0;
	while ((map->map_2ptr[i] = get_next_line(fd)) != NULL)
	{	j = 0;
		while (map->map_2ptr[i][j])
		{
			if (map->map_2ptr[i][j] == '\n')
			map->map_2ptr[i][j] = '\0';
			j++;
		}
		i++;
	}
	map->map_2ptr[i] = NULL;
}

void	draw_map(char *mlx_ptr, char *win_ptr, t_map map)
{
	char	*img_ptr;
	int		img_width;
	int		img_height;
	int		i;
	int		j;

	i = 0;
	while (map.map_2ptr[i])
	{
		j = 0;
		while (map.map_2ptr[i][j] != '\0')
		{
			if (map.map_2ptr[i][j] == '1')
				img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/wall.xpm", &img_width, &img_height);
			else if (map.map_2ptr[i][j] == '0')
				img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/way.xpm", &img_width, &img_height);
			else if (map.map_2ptr[i][j] == 'P')
				img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/player.xpm", &img_width, &img_height);
			else if (map.map_2ptr[i][j] == 'C')
				img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/collettible.xpm", &img_width, &img_height);
			else if (map.map_2ptr[i][j] == 'E')
				img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/exit.xpm", &img_width, &img_height);
			mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	map(t_mlx *mlx, t_map *map)
{
	sizeof_map(&map);
	read_map(&map);
	draw_map(mlx->mlx_ptr, mlx->win_ptr, map->);
}