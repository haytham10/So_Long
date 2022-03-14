/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:20:19 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/14 20:22:49 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map1(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->img_height)
	{
		if (game->map.map[i][j] != '1')
			return (-1);
		i++;
	}
	i = 0;
	j = 0;
	while (j < game->img_width)
	{
		if (game->map.map[i][j] != '1')
			return (-1);
		j++;
	}
	return (0);
}

int	check_map2(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = game->img_width - 1;
	while (i < game->img_height)
	{
		if (game->map.map[i][j] != '1')
			return (-1);
		i++;
	}
	i = game->img_height - 1;
	j = 0;
	while (j < game->img_width)
	{
		if (game->map.map[i][j] != '1')
			return (-1);
		j++;
	}
	return (0);
}

int	check_map3(t_data *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < game->img_height)
	{
		while (j < game->img_width)
		{
			c = game->map.map[i][j];
			if (c != '0' && c != '1' && c != 'P' && c != 'C' && c != 'E')
				return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	check_min(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->img_height)
	{
		while (j < game->img_width)
		{
			if (game->map.map[i][j] == 'P')
				game->map_error.count_player++;
			else if (game->map.map[i][j] == 'C')
				game->map_error.count_coll++;
			else if (game->map.map[i][j] == 'E')
				game->map_error.count_exit++;
			j++;
		}
		i++;
		j = 0;
	}
	if (game->map_error.count_player < 1 || game->map_error.count_coll < 1
		|| game->map_error.count_exit < 1)
		return (-1);
	else
		return (0);
}

int check_square(t_data *game)
{
	int i;
	int	width;

	width = ft_strlen(game->map.map[0]);
	i = 1;
	while (i < game->img_height)
	{
		if ((int)ft_strlen(game->map.map[i]) != width)
			return (-1);
		i++;
	}
	return (0);
}