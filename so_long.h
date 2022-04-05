/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:24:50 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/05 22:46:00 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
#define	SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "./mlx/mlx.h"
#include "./mlx/mlx_hooks.h"
#include "./libft/libft.h"

// #typedef struct	s_game
// {
// 	void	*mlx;
// 	void	*win;
// 	char	**map;
// 	int		map_w;
// 	int		map_h;
// 	int		img_w;
// 	int		img_h;
// 	void	*wall;
// 	void	*floor;
// 	void	*coll;
// 	void	*enemy;
// 	void	*exit;
// 	void	*player;
// 	int		player_x;
// 	int		player_y;
// 	int		c_coll;
// 	int		moves;
// 	int		frame;
// 	int		loop;
// 	int		gg;
// }	t_game;

typedef	struct s_enemy
{
	int		x_enemy;
	int		y_enemy;
	int		sign;
	int		x;
	int		move;
	int		sleep;
	int		s_move;
	char	*imgs[8];
}		t_enemy;

typedef	struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	int		win_w;
	int		win_h;
	int		x_player;
	int		y_player;
	int		movement;
	char	**map;
	int		coll;
	t_enemy	enemies;
}		t_game;

typedef	struct s_map
{
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;
}		t_map;

void	errooor(char *str);
int		file_check(char *map);
int		get_height(char **map);
void	error_handler(t_game *game, char *msg);
void	map_check(t_game *game);
void	check_characters(t_game *game);
void	init_game(t_game *game);
char	**get_map(char *fileName);
int		get_height(char **map);
void	load_texture(char p, int x, int y, t_game *game);
void	load_img(t_game *game, int x, int y, char *img);
void	load_text(t_game *game);
void	use_door(t_game *game);
void	get_coll(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
int		animation(t_game *game);
void	render_img(t_game *game);
void	move_enemy(t_game *game);
void	open_door(t_game *game);
int		enemy_pos(t_game *game);

#endif