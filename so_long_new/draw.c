/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:31:53 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/14 20:41:42 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_floor(t_data *floor, int i, int j)
{
	mlx_put_image_to_window(floor->mlx_ptr, floor->mlx_win, floor->floor,
		i * 100, j * 100);
}

void	draw_wall(t_data *wall, int i, int j)
{
	mlx_put_image_to_window(wall->mlx_ptr, wall->mlx_win, wall->wall,
		i * 100, j * 100);
}

void	draw_exit(t_data *exit, int i, int j)
{
	mlx_put_image_to_window(exit->mlx_ptr, exit->mlx_win, exit->exit,
		i * 100, j * 100);
}

void	draw_coll(t_data *coll, int i, int j)
{
	mlx_put_image_to_window(coll->mlx_ptr, coll->mlx_win, coll->coll,
		i * 100, j * 100);
}

void	draw_player(t_data *player, int i, int j)
{
	mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->player,
		i * 100, j * 100);
}
