/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:56:41 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/08 23:12:51 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_enemy(t_game *game)
{
	game->enemy.img[0] = "assets/enemy0.xpm";
	game->enemy.img[1] = "assets/enemy1.xpm";
	game->enemy.img[2] = "assets/enemy2.xpm";
	game->enemy.img[3] = "assets/enemy3.xpm";
	game->enemy.img[4] = "assets/enemy4.xpm";
	game->enemy.img[5] = "assets/enemy5.xpm";
	game->enemy.img[6] = "assets/enemy6.xpm";
	game->enemy.img[7] = "assets/enemy7.xpm";
	load_img(game, "assets/floor.xpm",
		game->enemy.x * 50, game->enemy.y * 50);
	load_img(game, game->enemy.img[game->enemy.count],
		game->enemy.x * 50, game->enemy.y * 50);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;
	int	x_map;
	int	y_map;
	int	i;

	y = 0;
	y_map = 0;
	i = game->win_w;
	while (game->win_h > 0)
	{
		x = 0;
		x_map = 0;
		while (game->win_w > 0)
		{
			load_texture(game, game->map[y_map][x_map], x, y);
			x_map++;
			x += 50;
			game->win_w--;
		}
		game->win_w = i;
		y_map++;
		y += 50;
		game->win_h--;
	}
}

void	open_door(t_game *game)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	i = load_height(game->map);
	while (y != i)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				load_img(game, "assets/floor.xpm", x * 50, y * 50);
				load_img(game, "assets/open_exit.xpm", x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
}
