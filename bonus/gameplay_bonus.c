/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:25:33 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/08 22:14:45 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	enemy_pos(t_game *game)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = load_height(game->map);
	if (game->enemy.sign)
	{
		while (y != i)
		{
			x = 0;
			while (game->map[y][x])
			{
				if (e_check(game, x, y))
					return (1);
				x++;
			}
			y++;
		}
		return (0);
	}
	return (1);
}

void	move_enemy(t_game *game)
{
	load_img(game, "../assets/floor.xpm", game->enemy.x * 50, game->enemy.y * 50);
	if (game->map[game->enemy.y][game->enemy.x + 1] != '1'
		&& game->map[game->enemy.y][game->enemy.x + 1] != 'E'
		&& game->map[game->enemy.y][game->enemy.x + 1] != 'C'
		&& game->enemy.move == 0)
		game->enemy.x++;
	else
		game->enemy.move = 1;
	if (game->map[game->enemy.y][game->enemy.x - 1] != '1'
		&& game->map[game->enemy.y][game->enemy.x - 1] != 'E'
		&& game->map[game->enemy.y][game->enemy.x - 1] != 'C'
		&& game->enemy.move == 1)
		game->enemy.x--;
	else
		game->enemy.move = 0;
}

void	game_over(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
}

void	get_coll(t_game *game)
{
	game->coll--;
	game->map[game->enemy.y / 50][game->enemy.x / 50] = '0';
	load_img(game, "../assets/floor.xpm", game->x_player, game->y_player);
}

int	close_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
	return (0);
}
