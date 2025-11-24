#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void sizeof_map(t_map *map)
{
    char *line;
    int  fd;

    fd = open(map->path, O_RDONLY);
    if (fd == -1)
    {       
        write(2, "Error\nmap_size/open: -1\n", 24);
        free(map->path);
        exit(1);
    }
    map->width = 0;
    map->height = 0;
    while ((line = get_next_line(fd)))
    {
        if (map->width == 0)
        {
            while (line[map->width] && line[map->width] != '\n')
                map->width++;
        }
        map->height++;
        free(line);
    }
    close(fd);
}

static void read_map_data_errors(int status, int closeble)
{
    if (status == 0)
        write(2, "Error\nread_map/open : -1\n", 25);
    else
    {
        write(2, "Error\nmap_read/malloc/map->data: NULL", 37);
        close(closeble);
    }
    exit(1);
}

void read_map_data(t_map *map)
{
    int     fd;
    int     i;
    int     j;

    fd = open(map->path, O_RDONLY);
    if (fd == -1)
        read_map_data_errors(0, 0);
    map->data = malloc(sizeof(char *) * (map->height + 1));
    if (!map->data)
        read_map_data_errors(1, fd);
    i = 0;
    while ((map->data[i] = get_next_line(fd)))
    {
        j = 0;
        while ((map->data[i][j] != '\0'))
        {
            if (map->data[i][j] == '\n')
                map->data[i][j] = '\0';
            j++;
        }
        i++;
    }
    map->data[i] = NULL;
    close(fd);
}

static void	save_player_loc(t_map *map, int x, int y)
{
	map->player_loc[0] = y;
	map->player_loc[1] = x;
	map->player++;
}

int read_map_args(t_map *map)
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
