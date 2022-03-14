/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:24:40 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/14 20:34:48 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_data *game)
{
	game->p_floor = "./imgs/floor.xpm";
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, game->p_floor,
		&game->x, &game->y);
	game->p_wall = "./imgs/wall.xpm";
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, game->p_wall,
		&game->x, &game->y);
	game->p_player = "./imgs/player.xpm";
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, game->p_player,
		&game->x, &game->y);
	game->p_exits = "./imgs/exit.xpm";
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, game->p_exits,
		&game->x, &game->y);
	game->p_coll = "./imgs/coll.xpm";
	game->coll = mlx_xpm_file_to_image(game->mlx_ptr, game->p_coll,
		&game->x, &game->y);
	
}

void	set_player(t_data *game, int i, int j)
{
	game->m_player.h = i;
	game->m_player.v = j;
	draw_player(game, i, j);
}