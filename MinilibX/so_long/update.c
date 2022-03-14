/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:21:51 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/14 15:27:03 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	iscoll(t_data *data)
{
	int	k;

	k = 0;
	while (k < data->game->count_coll)
	{
		if (data->game->coll[k].x == data->game->player.x
			&& data->game->coll[k].y == data->game->player.y)
		{
			data->game->coll[k].x = -1;
			data->game->coll[k].y = -1;
			data->game->p_coll++;
		}
		k++;
	}
}

static void	moved(t_data *data, int x, int y)
{
	if (data->game->player.x != x || data->game->player.y != y)
	{
		data->game->p_move++;
		ft_putnbr(data->game->p_move);
	}
}

void	update(t_data *data)
{
	int	x;
	int y;

	x = data->game->player.x;
	y = data->game->player.y;
	if (data->game->p_up != 0)
		move_up(data, x, y);
	else if (data->game->p_down != 0)
		move_down(data, x, y);
	else if (data->game->p_left != 0)
		move_left(data, x, y);
	else if (data->game->p_right != 0)
		move_right(data, x, y);
	moved(data, x, y);
	iscoll(data);
	draw(data);
	if (data->game->exit.x == data->game->player.x
		&& data->game->exit.y == data->game->player.y)
		if (data->game->count_coll == data->game->p_coll)
			destroyer(data, 0);
}