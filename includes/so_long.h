#ifndef SO_LONG_H
# define SO_LONG_H

//şimdilik mlx verilerinin karmaşasını ortadan kaldırsın diye bu struct ı tanımlıyorum sonradan entegre edece
typedef struct s_mlx
{
	void	*init_p;
	void	*win_p;
}	t_mlx;

typedef struct s_map
{
	char	**map_pp;
	char	*path_p;
	int		X;
	int		Y;
	int		P;
	int		C;
	int		E;
	int		player_X;
	int		player_Y;
}			t_map;

void	map_main(t_mlx *mlx, t_map *map);
void	check_arg(t_map *map, char *arg);

#endif