/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:17:48 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/14 20:23:42 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG__H
# define SO_LONG__H

#include <mlx.h>
#include "mlx_hooks.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

typedef	struct s_map
{
	char	**map;
}	t_map;

typedef	struct s_player
{
	int		h;
	int		v;
	t_map	map;
}	t_player;

typedef	struct s_error
{
	int	count_coll;
	int	count_player;
	int	count_exit;
}	t_error;

typedef	struct s_data
{
	t_map		map;
	t_player	m_player;
	t_error		map_error;
	void		*mlx_ptr;
	void		*mlx_win;
	void		*player;
	void		*exit;
	void		*coll;
	void		*wall;
	void		*floor;
	int			count_coll;
	int			coll_sum;
	int			steps;
	char		*p_wall;
	char		*p_floor;
	char		*p_player;
	char		*p_exits;
	char		*p_coll;
	int			img_width;
	int			img_height;
	int			x;
	int			y;
}	t_data;

int		map_check(char *map);
void	death(char *msg);
void	f_errors(t_data *game);
int		check_map1(t_data *game);
int		check_map2(t_data *game);
int		check_map3(t_data *game);
int		check_min(t_data *game);
int		check_square(t_data *game);

#endif
