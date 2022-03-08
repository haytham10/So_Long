/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:17:47 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/06 01:12:38 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key, t_data *data)
{
	if (key == KEY_ESC)
		destroyer(data, 0);
	if (key == KEY_W)
		data->game->p_up = 1;
	if (key == KEY_A)
		data->game->p_left = 1;
	if (key == KEY_D)
		data->game->p_right = 1;
	if (key == KEY_S)
		data->game->p_down = 1;
	update(data);
	return (0);
}

int key_release(int key, t_data *data)
{
	if (key == KEY_W)
		data->game->p_up = 0;
	if (key == KEY_S)
		data->game->p_down = 0;
	if (key == KEY_A)
		data->game->p_left = 0;
	if (key == KEY_D)
		data->game->p_right = 0;
	update(data);
	return (0);
}

int	destroy_hook(int key, t_data *data)
{
	(void)key;
	(void)data;
	destroyer(0, 0);
	return (0);
}