/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:17:48 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/09 15:49:29 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG__H
# define SO_LONG__H

#include "../mlx/mlx.h"
#include "mlx_hooks.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef	struct s_coor
{
	int	x;
	int	y;
}	t_coor;

typedef	struct s_game
{
	int		**map;
	int		height;
	int		width;
	t_coor	player;
	int		p_up;
	int		p_down;
	int		p_left;
	int		p_right;
	int		p_move;
	int		p_coll;
	t_coor	exit;
	t_coor	*coll;
	int		count_player;
	int		count_coll;
	int		count_exit;
}	t_game;

typedef	struct s_img
{
	void	*mlx_img;
	char	*addr;
	char	*data;
	int		bpp;
	int		len;
	int		endian;
	int		img_height;
	int		img_width;
}	t_img;

typedef	struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	*mlx_img;
	t_game	*game;
	t_img	*player;
	t_img	*exit;
	t_img	*coll;
	t_img	*wall; // 30B - W // 16B - H
	t_img	*floor;
}	t_data;

t_data			*data_init(char *name);
int				map_check(char *map);
void			destroyer(t_data *data, char *msg);
void			dest_game(t_game *game);
void			death(char *msg);
void			game_init(t_data *data, char *name);
void			map_init(t_data *data, char *name);
void			map_read(t_data *data, char *file);
void			map_parsing(t_data *data, char *file);
void			map_height(t_data *data, char *file);
void			map_width(t_data *data, char *file);
void			map_isvalid(t_data *data, char *file);
void			draw(t_data *data);
void			draw_pixel(t_img *img, int x, int y, int color);
void			move_up(t_data *data, int x, int y);
void			move_down(t_data *data, int x, int y);
void			move_left(t_data *data, int x, int y);
void			move_right(t_data *data, int x, int y);
void			update(t_data *data);
int				key_press(int key, t_data *data);
int 			key_release(int key, t_data *data);
int				destroy_hook(int key, t_data *data);
unsigned int	d_rgb_to_int(int o, int r, int g, int b);
unsigned int	d_get_pixel(t_img *img, int x, int y);
void			ft_putchar(int c);
void			ft_putstr(char *str);
char			*ft_strjoin(char *s1, char *s2);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void 			ft_putnbr(int n);
int				ft_strlen(char *s);

#endif