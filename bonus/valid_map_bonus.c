/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:57:39 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/08 22:29:15 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	valid_rect(t_game *game)
{
	int	i;
	int	x;
	int	y;
	int	height;

	height = load_height(game->map);
	y = 0;
	i = 0;
	while (y != height)
	{
		x = 0;
		while (game->map[y][x])
			x++;
		y++;
		if (i != 0)
		{
			if (i != x)
				f_error("MAP NOT RECTANGULAR");
		}
		else
			i = x;
	}
}

static int	valid_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static void	valid_wall(t_game *game)
{
	int		i;

	if (valid_line(game->map[0]))
		f_error("MAP NOT SURROUNDED BY WALLS");
	i = load_height(game->map) - 1;
	while (i)
	{
		if (game->map[i][0] != '1' ||
			game->map[i][ft_strlen(game->map[0]) - 1] != '1')
			f_error("MAP NOT SURROUNDED BY WALLS");
		i--;
	}
	if (valid_line(game->map[load_height(game->map) - 1]))
		f_error("MAP NOT SURROUNDED BY WALLS");
}

static void	valid_char(t_game *game)
{
	t_map	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.y = load_height(game->map) - 1;
	while (map.y--)
	{
		map.x = 0;
		while (game->map[map.y][map.x])
		{
			if (game->map[map.y][map.x] == 'C')
				map.c++;
			else if (game->map[map.y][map.x] == 'P')
				map.p++;
			else if (game->map[map.y][map.x] == 'E')
				map.e++;
			else if (game->map[map.y][map.x] != '1'
				&& game->map[map.y][map.x] != '0')
				f_error("MAP CONTAINS INVALID CHARACTERS");
			map.x++;
		}
	}
	if (map.c == 0 || map.p == 0 || map.e == 0)
		f_error("MAP MUST CONTAIN: PLAYER = 1\nEXIT > 1\nCOLLECTABLE > 1");
}

void	valid_map(t_game *game)
{
	valid_rect(game);
	valid_wall(game);
	valid_char(game);
}
