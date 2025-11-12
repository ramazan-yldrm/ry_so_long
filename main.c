#include "mlx/mlx.h"
#include "so_long.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char	**read_map(char **map)
{
	char	*line;
	int		fd;
	int		i;

	fd = open("../maps/map1.ber", O_RDWR, 0777);
	i = 0;
	map[0] = malloc(sizeof(char *));
	while ((line = get_next_line(fd)) != NULL)
	{
		**map = *line;
		i++;
	}
	return (map);
}

void	draw_map(char *mlx_ptr, char *win_ptr, char *map[])
{
	char	*img_ptr;
	int		img_width;
	int		img_height;
	int		i;
	int		j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == '1')
				img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/wall.xpm", &img_width, &img_height);
			else if (map[i][j] == '0')
				img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/way.xpm", &img_width, &img_height);
			else if (map[i][j] == 'P')
				img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/player.xpm", &img_width, &img_height);
			else if (map[i][j] == 'C')
				img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/collettible.xpm", &img_width, &img_height);
			else if (map[i][j] == 'E')
				img_ptr = mlx_xpm_file_to_image(mlx_ptr, "textures/player.xpm", &img_width, &img_height);
			mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map = NULL;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "so_long");
	read_map(map);
	draw_map(mlx_ptr, win_ptr, map);
	mlx_loop(mlx_ptr);
}
