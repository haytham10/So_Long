/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:17:46 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/18 22:56:57 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anime_player(t_game *game)
{
	int	step;

	step = 4;
	if (game->move_status == 2)
		handle_location(game, step, 0);
	else if (game->move_status == 1)
		handle_location(game, -step, 0);
	else if (game->move_status == 4)
		handle_location(game, 0, -step);
	else if (game->move_status == 3)
		handle_location(game, 0, step);
	game->offset += step;
	if (game->offset > 5000)
		game->offset = 0;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player.obj->img, game->player.x, game->player.y);
	game->player.obj = game->player.obj->next;
}

void	anime_coll(t_game *game)
{
	t_coord	*coll;

	coll = game->coll.coll;
	while (coll)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->objs.floor, coll->x, coll->y);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->coll.obj->img, coll->x, coll->y);
		coll = coll->next;
	}
	game->coll.obj = game->coll.obj->next;
}