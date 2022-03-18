/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:38:54 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/18 23:07:29 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *game)
{
	t_map	map;
	char	*line;
	int		i;
	int		j;

	map = game->map;
	i = 0;
	while (i < map.rows)
	{
		line = map.map[i];
		j = 0;
		while (j < map.cols)
		{
			if (line[j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->objs.wall, j * 50, i * 50);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->objs.floor, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	draw_objs(t_game *game)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (i < game->map.rows)
	{
		line = game->map.map[i];
		j = 0;
		while (j < game->map.cols)
		{
			if (line[j] == 'P')
			{
				game->player.x = j * 50;
				game->player.y = i * 50;
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->player.obj->img, game->player.x, game->player.y);
			}
			else if (line[j] == 'C')
				lst_add(&game->coll.coll, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	draw_exit(t_game *game)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (i < game->map.rows)
	{
		line = game->map.map[i];
		j = 0;
		while (j < game->map.cols)
		{
			if (line[j] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->objs.exit, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	draw_init(t_game *game)
{
	draw_map(game);
	anime_coll(game);
	draw_exit(game);
	game->player.obj = game->player.init;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player.obj->img, game->player.x, game->player.y);
	game->move_status = 0;
}