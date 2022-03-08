/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:27:03 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/05 21:38:12 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_coor(t_data *data, char *file, int k, int *o)
{
	if (file[k] == 'P')
	{
		data->game->player.x = k % (data->game->width + 1);
		data->game->player.y = k / (data->game->width + 1);
		file[k] = '0';
	}
	else if (file[k] == 'E')
	{
		data->game->exit.x = k % (data->game->width + 1);
		data->game->exit.y = k / (data->game->width + 1);
		file[k] = '0';
	}
	else if (file[k] == 'C')
	{
		data->game->coll[*o].x = k % (data->game->width + 1);
		data->game->coll[*o].y = k / (data->game->width + 1);
		file[k] = '0';
		(*o)++;
	}
}

static void	free_map(t_data *data, char *file, int **m, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
	data->game->map = 0;
	free(file);
	destroyer(data, "map_parsing/malloc");
}

void	map_parsing(t_data *data, char *file)
{
	int	i;
	int	j;
	int	k;
	int	o;

	o = 0;
	k = 0;
	j = -1;
	while (++j < data->game->height)
	{
		data->game->map[j] = (int *)malloc(sizeof(int) * data->game->width);
		if (data->game->map[j] == 0)
			free_map(data, file, data->game->map, j);
		i = 0;
		while (i < data->game->width)
		{
			get_coor(data, file, k, &o);
			data->game->map[j][i++] = file[k++] - 48;
		}
		k++;
	}
}