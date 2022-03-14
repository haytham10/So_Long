/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:30:49 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/14 16:02:03 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	texture_load(t_data *data, t_img **img, char *path)
{
	int	w;
	int	h;

	*img = mlx_xpm_file_to_image(data->mlx_ptr, path, &w, &h);
	if (*img == 0)
		destroyer(data, "Can't Load Textures");
	(*img)->img_width = w;
	(*img)->img_height = h;
}

static void	texture_init(t_data *data)
{
	texture_load(data, &data->player, "./idle_right.xpm");
	texture_load(data, &data->exit, "./exit.xpm");
	texture_load(data, &data->coll, "./coll.xpm");
	texture_load(data, &data->wall, "./wall.xpm");
	texture_load(data, &data->floor, "./floor.xpm");
}

static void	render_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == 0)
		destroyer(data, "MLX not loaded");
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->game->width * 40,
			data->game->height * 40, "so_long");
	if (data->mlx_win == 0)
		destroyer(data, "Can't Create a Window");
	// data->mlx_img = mlx_new_image(data->mlx_ptr, data->game->width * 40,
	// 		data->game->height * 40);
	// if (data->mlx_img == 0)
	// 	destroyer(data, "Can't Create an Image");
}

t_data	*data_init(char *name)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == 0)
		destroyer(0, "Problem with Malloc in 'data_init'\n");
	data->game = 0;
	data->floor = 0;
	data->exit = 0;
	data->coll = 0;
	data->wall = 0;
	data->player = 0;
	data->mlx_ptr = 0;
	data->mlx_win = 0;
	data->mlx_img = 0;
	game_init(data, name);
	render_init(data);
	texture_init(data);
	return (data);
}
