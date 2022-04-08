/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:14:40 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/08 22:26:39 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	load_img(game, "assets/floor.xpm", game->x_player, game->y_player);
	if (game->map[(game->y_player / 50) - 1][(game->x_player / 50)] == 'E')
	{
		if (game->coll <= 0)
			game_over(game);
	}
	if (game->map[(game->y_player / 50) - 1][game->x_player / 50] != '1')
	{
		game->y_player -= 50;
		load_steps(game);
	}
	if (game->map[game->y_player / 50][game->x_player / 50] == 'C')
		get_coll(game);
	load_img(game, "assets/bsonic.xpm", game->x_player, game->y_player);
}

void	move_down(t_game *game)
{
	load_img(game, "assets/floor.xpm", game->x_player, game->y_player);
	if (game->map[(game->y_player / 50) + 1][game->x_player / 50] == 'E')
	{
		if (game->coll <= 0)
			game_over(game);
	}
	else if (game->map[(game->y_player / 50) + 1][game->x_player / 50] != '1')
	{
		game->y_player += 50;
		load_steps(game);
	}
	if (game->map[game->y_player / 50][game->x_player / 50] == 'C')
		get_coll(game);
	load_img(game, "assets/fsonic.xpm", game->x_player, game->y_player);
}

void	move_right(t_game *game)
{
	load_img(game, "assets/floor.xpm", game->x_player, game->y_player);
	if (game->map[game->y_player / 50][(game->x_player / 50) + 1] == 'E')
	{
		if (game->coll <= 0)
			game_over(game);
	}
	else if (game->map[game->y_player / 50][(game->x_player / 50) + 1] != '1')
	{
		game->x_player += 50;
		load_steps(game);
	}
	if (game->map[game->y_player / 50][game->x_player / 50] == 'C')
		get_coll(game);
	load_img(game, "assets/rsonic.xpm", game->x_player, game->y_player);
}

void	move_left(t_game *game)
{
	load_img(game, "assets/floor.xpm", game->x_player, game->y_player);
	if (game->map[game->y_player / 50][(game->x_player / 50) - 1] == 'E')
	{
		if (game->coll <= 0)
			game_over(game);
	}
	else if (game->map[game->y_player / 50][(game->x_player / 50) - 1] != '1')
	{
		game->x_player -= 50;
		load_steps(game);
	}
	if (game->map[game->y_player / 50][game->x_player / 50] == 'C')
		get_coll(game);
	load_img(game, "assets/lsonic.xpm", game->x_player, game->y_player);
}
