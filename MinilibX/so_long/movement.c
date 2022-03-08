/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:23:25 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/05 23:00:15 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data, int x, int y)
{
	if (data->game->map[y - 1][x] == 0)
		data->game->player.y -= 1;
}

void	move_down(t_data *data, int x, int y)
{
	if (data->game->map[y + 1][x] == 0)
		data->game->player.y += 1;
}

void	move_left(t_data *data, int x, int y)
{
	if (data->game->map[y][x - 1] == 0)
		data->game->player.x -= 1;
}
void	move_right(t_data *data, int x, int y)
{
	if (data->game->map[y][x + 1] == 0)
		data->game->player.x += 1;
}