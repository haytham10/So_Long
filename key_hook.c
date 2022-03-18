/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:37:11 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/18 23:51:05 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_hook(int key, t_game *game)
{
	if (key == 2)
	{
		game->move_status = 2;
		game->offset = game->player.x;
		game->player.obj = game->player.right_obj;
		game->player.init = game->player.right_init;
	}
	else if (key == 0)
	{
		game->move_status = 1;
		game->offset = game->player.x;
		game->player.obj = game->player.left_obj;
		game->player.init = game->player.left_init;
	}
	else if (key == 13)
	{
		game->move_status = 4;
		game->offset = game->player.y;
	}
	else if (key == 1)
	{
		game->move_status = 3;
		game->offset = game->player.y;
	}
	// ft_printf("STEP : %d\n", ++(game->steps));
}

int	key_hook(int key, t_game *game)
{
	if (game->move_status == 0 && (key == 0 ||
		key == 2 || key == 1 || key == 13))
		move_hook(key, game);
	if (key == 53)
		close_game(game);
	return (1);
}
