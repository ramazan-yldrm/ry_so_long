#include "../libft/libft.h"
#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	check_arg(t_map *map, char *arg)
{
	char	*path_p;
	int		fd;

	path_p = ft_strjoin("maps/", arg);
	if (!path_p)
	{
		write(2, "Error\nft_strjoin: NULL\n", 23);
		exit(1);
	}
	fd = open(path_p, O_RDONLY);
	if (fd == -1)
	{
		//hata yönetimi sonradan düzeltilecek
		write(2, "Error\nfile not found\n", 22);
		free(path_p);
		exit(1);
	}
	map->path_p = path_p;
	close(fd);
}
