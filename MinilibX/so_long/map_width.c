/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:56:39 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/06 01:17:46 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_width(t_data *data, char *file)
{
	data->game->width = 0;
	while (file[data->game->width] && file[data->game->width] != '\n')
		data->game->width++;
	if (data->game->width == 0 || file[data->game->width] == 0)
	{
		free(file);
		destroyer(data, "Non-Valid Map File");
	}
}