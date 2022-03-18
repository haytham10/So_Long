/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:22:50 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/18 23:06:20 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_wall(t_game *game, int offsetX, int offsetY)
{
	char	**map;
	int		row;
	int		col;

	map = game->map.map;
	row = (game->player.y + offsetY) / 50;
	col = (game->player.x + offsetX) / 50;
	if (offsetX > 0)
		col += 1;
	else if (offsetY > 0)
		row += 1;
	if (map[row][col] != '1' ||
		(!((game->player.y + offsetY) % 50) &&
			!((game->player.x + offsetX) % 50)))
	{
		game->player.x = game->player.x + offsetX;
		game->player.y = game->player.y + offsetY;
	}
}

void	handle_coll(t_game *game, int offsetX, int offsetY)
{
	char	**map;
	int		row;
	int		col;

	map = game->map.map;
	row = (game->player.y + offsetY);
	col = (game->player.x + offsetX);
	if (!(row % 50) && !(col % 50)
		&& map[row / 50][col / 50] == 'C')
	{
		lst_delete(&game->coll.coll, game->player.x + offsetX,
			game->player.y + offsetY);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->objs.floor,
			game->player.x + offsetX, game->player.y + offsetY);
	}
}

void	handle_exit(t_game *game, int offsetX, int offsetY)
{
	char	**map;
	int		row;
	int		col;

	map = game->map.map;
	row = (game->player.y + offsetY);
	col = (game->player.x + offsetX);
	if (!(row % 50) && !(col % 50)
		&& map[row / 50][col / 50] == 'E')
	{
		if (!game->coll.coll)
			close_game(game);
	}
}

void	handle_location(t_game *game, int offsetX, int offsetY)
{
	handle_wall(game, offsetX, offsetY);
	handle_coll(game, offsetX, offsetY);
	handle_exit(game, offsetX, offsetY);
}