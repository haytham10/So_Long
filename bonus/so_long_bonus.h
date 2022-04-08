/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:09:19 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/08 21:37:24 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13

typedef struct s_map
{
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;
}		t_map;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			sign;
	int			count;
	int			move;
	int			sleep;
	int			s_move;
	char		*img[8];
}		t_enemy;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	int		win_h;
	int		win_w;
	int		x_player;
	int		y_player;
	int		movement;
	char	**map;
	int		coll;
	t_enemy	enemy;
}		t_game;

void	f_error(char *str);
int		f_check(char *str);
int		e_check(t_game *game, int x, int y);
char	**load_map(char *file);
int		load_height(char **map);
void	valid_map(t_game *game);
void	load_img(t_game *game, char *img, int x, int y);
void	load_texture(t_game *game, char obj, int x, int y);
void	load_steps(t_game *game);
void	render_map(t_game *game);
void	render_img(t_game *game);
void	game_init(t_game *game);
int		key_press(int key, t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	get_coll(t_game *game);
void	game_over(t_game *game);
int		animation(t_game *game);
int		enemy_pos(t_game *game);
void	move_enemy(t_game *game);
void	open_door(t_game *game);
int		close_game(t_game *game);

#endif