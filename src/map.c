#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//neden mapin boyutunu hesap ediyorum çünkü bunu yapmadığım durumlarda seg fault alıyorum bunu anlamlandırmalıyım
void	sizeof_map(t_map *map)
{
	int		fd;

	fd = open(map->path_p, O_RDONLY);
	if (fd == -1)
	{
		//hata yönetimi sonradan düzeltilecek
		write(2, "Error\nfile not found\n", 22);
		free(map->path_p);
		exit(1);
	}
	map->X = 0;
	map->Y = 0;
		char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (map->X == 0)
		{
			while (line[map->X])
				map->X++;
		}
		map->Y++;
		free(line);
	}
	map->X--;
	close(fd);
}

void	read_map(t_map *map)
{
	int	fd;
	int	i;
	int	j;

	fd = open(map->path_p, O_RDONLY);
	if (fd == -1)
		exit(1);
	map->map_pp = malloc(sizeof(char *) * map->Y);
	if (!map->map_pp)
		exit(1);
	i = 0;
	while ((map->map_pp[i] = get_next_line(fd)) != NULL)
	{
		j = 0;
		while (map->map_pp[i][j])
		{
			if (map->map_pp[i][j] == '\n')
				map->map_pp[i][j] = '\0';
			j++;
		}	
		i++;
	}
	map->map_pp[i] = NULL;
	close(fd);
}

int	is_map_square(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_pp[i])
	{
		j = 0;
		while (map->map_pp[i][j])
			j++;
		if (j != map->X)
			return (0);
		i++;
	}
	return (1);
}

int	is_edges_close(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_pp[i])
	{
		j = 0;
		while (map->map_pp[i][j])
		{
			if (map->map_pp[0][j] != '1')
				return (0);
			if (map->map_pp[map->Y - 1][j] != '1')
				return (0);
			if (map->map_pp[i][0] != '1')
				return (0);
			if (map->map_pp[i][map->X - 1] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void take_elemans(t_map *map)
{
	int	i;
	int	j;

	map->P = 0;
	map->C = 0;
	map->E = 0;
	i = 0;
	while (map->map_pp[i])
	{
		j = 0;
		while (map->map_pp[i][j])
		{
			if (map->map_pp[i][j] == 'P')
				map->P++;		
			if (map->map_pp[i][j] == 'C')
				map->C++;
			if (map->map_pp[i][j] == 'E')
				map->E++;
			j++;
		}
		i++;
	}

	printf("      player : %d\n      collect : %d\n      exit : %d\n", map->P, map->C, map->E);
}

int check_map_arg(t_map *map)
{
	if (map->P != 1)
		return (0);
	if (map->E != 1)
		return (0);
	if (map->C < 1)
		return (0);
	return (1);
}

/* void	draw_map(t_mlx *mlx, char **map_pp)
{
	char	*img_p;
	int		img_width;
	int		img_height;
	int		i;
	int		j;

	i = 0;
	while (map_pp[i])
	{
		j = 0;
		while (map_pp[i][j] != '\0')
		{
			if (map_pp[i][j] == '1')
				img_p = mlx_xpm_file_to_image(mlx->init_p, "textures/wall.xpm", &img_width, &img_height);
			else if (map_pp[i][j] == '0')
				img_p = mlx_xpm_file_to_image(mlx->init_p, "textures/way.xpm", &img_width, &img_height);
			else if (map_pp[i][j] == 'P')
				img_p = mlx_xpm_file_to_image(mlx->init_p, "textures/player.xpm", &img_width, &img_height);
			else if (map_pp[i][j] == 'C')
				img_p = mlx_xpm_file_to_image(mlx->init_p, "textures/collettible.xpm", &img_width, &img_height);
			else if (map_pp[i][j] == 'E')
				img_p = mlx_xpm_file_to_image(mlx->init_p, "textures/exit.xpm", &img_width, &img_height);
			mlx_put_image_to_window(mlx->init_p, mlx->win_p, img_p, j * 64, i * 64);
			j++;
		}
		i++;
	}
} */

void	map_main(t_map *map)
{
	int a;
	int b;
	int c;

	sizeof_map(map);

	read_map(map);

	printf("      map_X: %d, map_Y: %d\n", map->X, map->Y);

	a = is_map_square(map);

	b = is_edges_close(map);

		take_elemans(map);

	c = check_map_arg(map);
	printf("      is_map_square : %d, is_edges_one : %d\n", a, b);
	printf("      check_map_arg : %d\n", c);

}