#ifndef SO_LONG_H
# define SO_LONG_H

//şimdilik mlx verilerinin karmaşasını ortadan kaldırsın diye bu struct ı tanımlıyorum sonradan entegre edece
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_map
{
	char	**map_2ptr;
	char	*path_ptr;
	int		width;
	int		heigth;
}			t_map;

void	map(t_mlx *mlx, t_map *map);

#endif