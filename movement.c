/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:11:37 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/05 18:30:52 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_coll(t_game *game)
{
	int	i;
	int	j;

	game->coll--;
	game->map[game->y_player / 50][game->x_player / 50] = '0';
	game->img = mlx_xpm_file_to_image(game->mlx, "./imgs/floor.xpm", &i, &j);
	mlx_put_image_to_window(game->mlx, game->win, game->img, game->x_player,
			game->y_player);
}

void	move_left(t_game *game)
{
	int		i;
	int		j;

	game->img = mlx_xpm_file_to_image(game->mlx,
		"./imgs/floor.xpm", &i, &j);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->x_player, game->y_player);
	if (game->map[game->y_player / 50][(game->x_player / 50) - 1] == 'E')
	{
		if (game->coll <= 0)
			use_door(game);
	}
	else if (game->map[game->y_player / 50][(game->x_player / 50) - 1] == '1')
	{
		(game->x_player) -= 50;
		load_text(game);
	}
	if (game->map[game->y_player / 50][game->x_player / 50] == 'C')
		get_coll(game);
	game->img = mlx_xpm_file_to_image(game->mlx,
		"./imgs/lsonic.xpm", &i, &j);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->x_player, game->y_player);
}

void	move_right(t_game *game)
{
	int		i;
	int		j;

	game->img = mlx_xpm_file_to_image(game->mlx,
		"./imgs/floor.xpm", &i, &j);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->x_player, game->y_player);
	if (game->map[game->y_player / 50][(game->x_player / 50) + 1] == 'E')
	{
		if (game->coll <= 0)
			use_door(game);
	}
	else if (game->map[game->y_player / 50][(game->x_player / 50) + 1] == '1')
	{
		(game->x_player) += 50;
		load_text(game);
	}
	if (game->map[game->y_player / 50][game->x_player / 50] == 'C')
		get_coll(game);
	game->img = mlx_xpm_file_to_image(game->mlx,
		"./imgs/rsonic.xpm", &i, &j);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->x_player, game->y_player);
}

void	move_up(t_game *game)
{
	int	i;
	int	j;

	game->img = mlx_xpm_file_to_image(game->mlx,
		"./imgs/floor.xpm", &i, &j);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->x_player, game->y_player);
	if (game->map[(game->y_player / 50) - 1][game->x_player / 50] == 'E')
	{
		if (game->coll <= 0)
			use_door(game);
	}
	else if (game->map[(game->y_player / 50) - 1][game->x_player / 50] == '1')
	{
		(game->y_player) -= 50;
		load_text(game);
	}
	if (game->map[game->y_player / 50][game->x_player / 50] == 'C')
		get_coll(game);
	game->img = mlx_xpm_file_to_image(game->mlx,
		"./imgs/bsonic.xpm", &i, &j);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->x_player, game->y_player);
}

void	move_down(t_game *game)
{
	int	i;
	int	j;

	game->img = mlx_xpm_file_to_image(game->mlx,
		"./imgs/floor.xpm", &i, &j);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->x_player, game->y_player);
	if (game->map[(game->y_player / 50) + 1][game->x_player / 50] == 'E')
	{
		if (game->coll <= 0)
			use_door(game);
	}
	else if (game->map[(game->y_player / 50) + 1][game->x_player / 50] == '1')
	{
		(game->y_player) += 50;
		load_text(game);
	}
	if (game->map[game->y_player / 50][game->x_player / 50] == 'C')
		get_coll(game);
	game->img = mlx_xpm_file_to_image(game->mlx,
		"./imgs/fsonic.xpm", &i, &j);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->x_player, game->y_player);
}
