/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:45:34 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/08 21:46:50 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	animation(t_game *game)
{	
	if (enemy_pos(game) != 0)
	{
		if (game->enemy.sleep-- <= 0)
		{
			game->enemy.count++;
			game->enemy.sleep = 5;
		}
		if (game->enemy.count == 3)
			game->enemy.count = 0;
		if (game->enemy.s_move-- <= 0)
		{
			move_enemy(game);
			game->enemy.s_move = 30;
		}
		if (game->enemy.y == game->y_player / 50
			&& game->enemy.x == game->x_player / 50)
		{
			ft_putstr("LOOOSER!!!\n");
			game_over(game);
		}
		render_img(game);
	}
	if (game->coll <= 0)
		open_door(game);
	return (0);
}
