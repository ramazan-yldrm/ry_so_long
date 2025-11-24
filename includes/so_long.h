/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:19:45 by ryildiri          #+#    #+#             */
/*   Updated: 2025/11/24 21:19:45 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

void	draw_map(t_game *game);
void	sizeof_map(t_map *map);
void	read_map_data(t_map *map);
void	load_textures(t_game *game);
void	read_map_args(t_map *map);
void	check_map(t_map *map);
void	destroy_textures(t_game *game);
void	free_all(char **str);

int		catch_key(int keycode, t_game *game);
int		close_game(t_game *game);
int		close_game(t_game *game);
int		check_path(t_map *map);
void	map_error(char *str, char **map_data);

#endif