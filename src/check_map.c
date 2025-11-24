#include "../includes/so_long.h"
#include <stdlib.h>
#include <unistd.h>

static int is_map_square(t_map *map)
{
    int i;
    int j;

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

static int is_map_close(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (map->data[i])
    {
        j = 0;
        if (map->width != 0)
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
        i++;
    }
    return (1);
}

void check_map(t_map *map)
{
    if (is_map_square(map) == 0)
    {
        write(2, "Error\nmap not square\n", 21);
        free_all(map->data);
        exit(1);
    }
    if(is_map_close(map) == 0)
    {
        write(2, "Error\nmap not square\n", 21);
        free_all(map->data);
        exit(1);
    }
    if (map->player != 1)
    {
        write(2, "Error\nmap not square\n", 21);
        free_all(map->data);
        exit(1);
    }
    if (map->exit != 1)
    {
        write(2, "Error\nmap not square\n", 21);
        free_all(map->data);
        exit(1);
    }
    if (map->coin < 1)
    {
        write(2, "Error\nmap not square\n", 21);
        free_all(map->data);
        exit(1);
    }
}
