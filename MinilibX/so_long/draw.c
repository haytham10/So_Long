/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:41:44 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/14 15:59:59 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_square(t_data *data, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			color = d_get_pixel(img, i, j);
			if (color != d_rgb_to_int(0, 255, 255, 255))
				draw_pixel(data->mlx_img, x + i, y + j, color);
			i++;
			write(1, "ok", 2);
		}
		j++;
	}
}

static void	draw_env(t_data *data, int i, int j)
{
	int				k;

	if (data->game->exit.x == i && data->game->exit.y == j)
		draw_square(data, data->exit, i * 50, j * 50);
	k = -1;
	while (++k < data->game->count_coll)
		if (data->game->coll[k].x == i && data->game->coll[k].y == j)
			draw_square(data, data->coll, i * 50, j * 50);
	if (data->game->player.x == i && data->game->player.y == j)
		draw_square(data, data->player, i * 50, j * 50);
}

static void	draw_map(t_data *data)
{
	int				i;
	int				j;

	j = 0;
	while (j < data->game->height)
	{
		i = 0;
		while (i < data->game->width)
		{
			if (data->game->map[j][i] == 1)
			{	
				draw_square(data, data->wall, i * 50, j * 50);
				write(1, "ok", 2);
			}
			else
			{	
				write(1, "ok", 2);
				draw_square(data, data->floor, i * 50, j * 50);
			}
			draw_env(data, i, j);
			i++;
		}
		j++;
	}
}

void	draw(t_data *data)
{
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_img, 0, 0);
}
