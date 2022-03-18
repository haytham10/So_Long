/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:09:46 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/18 23:38:41 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
#define	SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "./mlx/mlx.h"
#include "./libft/libft.h"

typedef	struct l_list
{
	void			*img;
	struct l_list	*next;	
}	t_list;

typedef	struct s_player
{
	int		x;
	int		y;
	t_list	*init;
	t_list	*obj;
	t_list	*right_init;
	t_list	*left_init;
	t_list	*right_obj;
	t_list	*left_obj;
}	t_player;

typedef	struct s_coord
{
	int				x;
	int				y;
	struct s_coord	*next;
}	t_coord;

typedef struct s_coll
{
	t_coord	*coll;
	t_list	*obj;
}	t_coll;

typedef	struct s_enemy
{
	t_coord	*enemies;
	t_list	*obj;
}	t_enemy;

typedef struct s_objs
{
	void	*wall;
	void	*floor;
	void	*steps;
	void	*exit;
}	t_objs;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		c_player;
	int		c_coll;
	int		c_exit;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			move_status;
	int			offset;
	int			steps;
	t_map		map;
	t_objs		objs;
	t_player	player;
	t_coll		coll;
	t_enemy		enemy;
}	t_game;

void	death(char *str);
void	map_parsing(t_game *game, char *map);
void	read_map(t_game *game, char *filename);
void	count_objs(t_map *map);
int		map_check(char *map);
void	valid_char(char *line);
void	valid_len(char *src, int len);
void	valid_wall(t_map *map, int row_i);
void	valid_min(t_map *map);
char	*get_line(int fd);
void	anime_player(t_game *game);
void	anime_coll(t_game *game);
void	draw_init(t_game *game);
void	draw_map(t_game *game);
void	draw_objs(t_game *game);
void	draw_exit(t_game *game);
void	game_init(t_game *game);
void	imgs_init(t_game *game);
void	win_init(t_game *game);
int		close_game(t_game *game);
void	handle_location(t_game *game, int offsetX, int offsetY);
void	handle_wall(t_game *game, int offsetX, int offsetY);
void	handle_coll(t_game *game, int offsetX, int offsetY);
void	handle_exit(t_game *game, int offsetX, int offsetY);
int		key_hook(int key, t_game *game);
void	move_hook(int key, t_game *game);
int		loop_hook(t_game *game);
void	move_player(t_game *game);
int		lst_add(t_coord **lst, int x, int y);
void	lst_delete(t_coord **lst, int x, int y);
void	player_pos(t_game *game, t_list **objs, char *path, int cnt);

#endif