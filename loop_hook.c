/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:46:52 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/18 22:59:00 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game)
{
	draw_objs(game);
	anime_coll(game);
	draw_exit(game);
	anime_player(game);
	if (game->offset % 50 == 0)
		draw_init(game);
}

int	loop_hook(t_game *game)
{
	static unsigned int frame;

	if (!(++frame % 500))
	{
		if (game->move_status != 0)
			move_player(game);
		else
			anime_coll(game);
	}
	return (1);
}