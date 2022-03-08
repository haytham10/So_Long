/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isvalid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:05:11 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/05 21:21:48 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	isborder(t_data *data, int i)
{
	if (i < data->game->width
		|| i > (data->game->width + 1) * (data->game->height -1)
		|| i % (data->game->width + 1) == 0
		|| i % (data->game->width + 1) == data->game->width - 1)
		return (1);
	return (0);
}

static void	isvalid(t_data *data, char *file, int i)
{
	if (file[i] == 'P')
		data->game->count_player++;
	else if (file[i] == 'E')
		data->game->count_exit++;
	else if (file[i] == 'C')
		data->game->count_coll++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
	{
		free(file);
		destroyer(data, "Non-Valid Map Content");
	}
}

void	map_isvalid(t_data *data, char *file)
{
	int	i;

	i = -1;
	while (file[++i] != 0)
	{
		if (file[i] == '\n')
			break ;
		if (isborder(data, i))
		{
			if (file[i] != '1')
			{
				free(file);
				destroyer(data, "Not Surrounded by Walls");
			}
		}
		else
			isvalid(data, file, i);
	}
	if (data->game->count_player != 1
		|| data->game->count_player != 1
		|| data->game->count_exit < 1)
	{
		free(file);
		destroyer(data, "Map Configuration Non-Valid");
	}
}
