/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:00:44 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/05 23:30:32 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_height(t_data *data, char *file)
{
	int	i;
	int	j;

	data->game->height = 1;
	i = data->game->width + 1;
	while (file[i] != 0)
	{
		j = 0;
		while (file[i + j] != 0 && file[i + j] != '\n')
			j++;
		if (data->game->width != j)
		{
			free(file);
			destroyer(data, "Non-Valid Map Format");
		}
		i += data->game->width + 1;
		data->game->height++;
	}		
}