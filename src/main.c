#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void	check_arg(t_map *map, char *arg)
{
	int	fd;

	arg = ft_strjoin("map/", arg);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		//hata yönetimi sonradan düzeltilecek
		free(arg);
		write(1, "file not found, plase sure", 26);
		write(1, "Error\n", 6);
		exit(1);
	}
	map->path_ptr = arg;
	//map->path_ptr için yer ayırıldı en son freelenmesi lazım	
}

int main(int ac, char *av[])
{
	t_map	map; 
	t_mlx	mlx;

	//bu durumda return 0 mı 1 mi bilemiyorum	
	if (ac != 2)
		return (1);
	check_arg(&map, av[1]);
	mlx.mlx_ptr = mlx_init();

	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "so_long");
	map(&mlx, &map);

	mlx_loop(mlx_ptr);
}
