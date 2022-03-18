/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:55:15 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/18 21:07:08 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_char(char *line)
{
	int i;

	i = 0;
	while(line[i])
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'C'
			|| line[i] == 'E' || line[i] == 'P'))
			death("NON-ALLOWED OBJECTS IN MAP");
		i++;
	}
	return ;
}

void	valid_len(char *src, int len)
{
	int src_len;

	src_len = ft_strlen(src);
	if (src_len == len)
		return ;
	else
		death("MAP FILE ROW LENGTH DIFFERENT");
}

void	valid_wall(t_map *map, int row_i)
{
	int		i;
	char	*row;

	row = map->map[row_i];
	if (row_i == 0 || row_i == map->rows - 1)
	{
		i = 0;
		while (i < map->cols)
		{
			if (row[i] != '1')
				death("MAP MUST BE SURROUNDED BY WALLS");
			i++;
		}
	}
	else
	{
		if (!(row[0] == '1' && row[map->cols - 1] == '1'))
			death("MAP MUST BE SURROUNDED BY WALLS");
	}
}

void	valid_min(t_map *map)
{
	if (map->c_player != 1)
		death ("MAP MUST HAVE ONE PLAYER");
	else if (map->c_exit < 1)
		death("MAP MUST HAVE AT LEAST ONE EXIT");
	else if (map ->c_coll < 1)
		death("MAP MUST HAVE AT LEAST ONE COLLECTABLE");
}