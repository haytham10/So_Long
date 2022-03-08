/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:29:14 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/02/28 13:20:59 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroyer(t_data *data, char *msg)
{
	if (data != 0)
	{
		if (data->wall != 0)
			mlx_destroy_image(data->mlx_ptr, data->wall);
		if (data->floor != 0)
			mlx_destroy_image(data->mlx_ptr, data->floor);
		if (data->coll != 0)
			mlx_destroy_image(data->mlx_ptr, data->coll);
		if (data->exit != 0)
			mlx_destroy_image(data->mlx_ptr, data->exit);
		if (data->player != 0)
			mlx_destroy_image(data->mlx_ptr, data->player);
		if(data->mlx_img != 0)
			mlx_destroy_image(data->mlx_ptr, data->mlx_img);
		if (data->mlx_win != 0)
			mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		if (data->mlx_ptr != 0)
			free(data->mlx_ptr);
		if (data->game != 0)
			dest_game(data->game);
		free(data);
	}
	death(msg);
}