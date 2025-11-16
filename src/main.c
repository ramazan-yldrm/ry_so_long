#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int ac, char *av[])
{
 	t_map	map;
	t_mlx	mlx;

	if (ac != 2)
	{
		write(2, "Error\n./so_long <map_file.ber>\n", 31);
		return (1);
	}
	check_arg(&map, av[1]);
	mlx.init_p = mlx_init();
	map_main(&mlx, &map);
	mlx_loop(mlx.init_p);
}
