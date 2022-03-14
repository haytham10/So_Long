/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:36:06 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/13 15:02:42 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_data *data, char *name)
{
	data->game = (t_game *)malloc(sizeof(t_game));
	if (data->game == 0)
		destroyer(data, "Problem with Malloc in 'game_init'\n");
	data->game->coll = 0;
	data->game->count_coll = 0;
	data->game->count_exit = 0;
	data->game->count_player = 0;
	data->game->map = 0;
	data->game->p_coll = 0;
	data->game->p_down = 0;
	data->game->p_left = 0;
	data->game->p_move = 0;
	data->game->p_right = 0;
	data->game->p_up = 0;
	map_init(data, name);
}