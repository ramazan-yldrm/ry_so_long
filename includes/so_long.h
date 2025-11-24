#ifndef SO_LONG_H
# define SO_LONG_H

#define NULL ((void*)0)


typedef struct s_map
{
	char	**data;
	char	*path;
	int		player_loc[2];
	int		width;
	int		height;
	int		player;
	int		coin;
	int		exit;
	int		step;
}	t_map;

typedef struct s_game
{
	t_map	map;
	void	*init;
	void	*win;
	void	*wall_texture;
	void	*floor_texture;
	void	*player_texture;
	void	*coin_texture;
	void	*exit_texture;
}			t_game;

void draw_map(t_game *game);
void sizeof_map(t_map *map);
void read_map_data(t_map *map);
void load_textures(t_game *game);

int check_map(t_map *map);
int read_map_args(t_map *map);
int catch_key(int keycode, t_game *game);
int close_game(t_game *game);

#endif