/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:55:12 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/09 15:42:25 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(t_data *data, char *file)
{
	map_width(data, file);
	map_height(data, file);
	map_isvalid(data, file);
	data->game->coll = (t_coor *)malloc(sizeof(t_coor) * data->game->count_coll);
	if (data->game->coll == 0)
	{
		free(file);
		destroyer(data, "map_parsing/malloc");
	}
	data->game->map = (int **)malloc(sizeof(int *) * data->game->height);
	if (data->game->map == 0)
	{
		free(file);
		destroyer(data, "map_parsing/malloc");
	}
	map_parsing(data, file);
}