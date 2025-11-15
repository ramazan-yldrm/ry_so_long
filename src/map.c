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
	map->x = 0;
	map->y = 1;
		char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (map->x == 0)
		{
			while (line[map->x])
				map->x++;
		}
		map->y++;
		free(line);
	}
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
	map->map_pp = malloc(sizeof(char *) * map->y);
	if (!map->map_pp)
		exit(1);
	i = 0;
	while((map->map_pp[i] = get_next_line(fd)) != NULL)
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

void	check_map(t_map *map)
{
	int	i;
	int	j;
	int k;
	int	count_x;
	int	count_y;

	i = 0;
	while (map->map_pp[i])
	{
		j = 0;
		count_x = 0;
		count_y = 0;
		if (map->x > map->y)
		{
			while (map->map_pp[i][j])
			{
				if(map->map_pp[i][j] == '1')
					count_x++;
				else
					count_x = 0;
				while (map->map_pp[i][j] >= 3)
				{
					k = i;
					if (map->map_pp[k][j] == '1')
						count_y++;
					else
						break ;
					k++;
				}
				j++;
			}
		}
		else
		{

		}
		i++;
	}
	printf("      count x : %d | count y : %d\n", count_x, count_y);
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
	sizeof_map(map);

	read_map(map);

	printf("      map_x: %d, map_y: %d\n", map->x, map->y);

	check_map(map);
}