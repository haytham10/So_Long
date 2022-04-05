/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:59:40 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/05 22:27:23 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static int check_line(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static void	check_rect(t_game *game)
{
	int	y;
	int	x;
	int	i;
	int	j;
	
	y = 0;
	j = 0;
	i = get_height(game->map);
	while (y != i)
	{
		x = 0;
		while (game->map[y][x] != '\0')
			x++;
		y++;
		if (j != 0)
		{
			if (j != x)
				errooor("MAP NOT RECTANGLE");
		}
		else
			j = x;
	}
}

static void	check_surrend(t_game *game)
{
	int		i;
	char	*e_msg;

	e_msg = "MAP NOT SURRENDERED";
	if (check_line(game->map[0]))
		error_handler(game, e_msg);
	i = get_height(game->map) - 1;
	while (i)
	{
		if (game->map[i][0] != '1' ||
			game->map[i][ft_strlen(game->map[i]) - 1] != '1')
		{
			error_handler(game, e_msg);
		}
		i--;
	}
	if (check_line(game->map[get_height(game->map) - 1]))
		error_handler(game, e_msg);
}

void	check_characters(t_game *game)
{
	t_map	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.y = get_height(game->map) - 1;
	while (map.y--)
	{
		map.x = 0;
		while (game->map[map.y][map.x] != '\0')
		{
			if (game->map[map.y][map.x] == 'P')
				map.p++;
			else if (game->map[map.y][map.x] == 'C')
				map.c++;
			else if (game->map[map.y][map.x] == 'E')
				map.e++;
			else if (game->map[map.y][map.x] != '1'
				&& game->map[map.y][map.x] != '0')
				error_handler(game, "MAP NOT VALID");
			map.x++;
		}
	}
	if (map.c == 0 || map.p == 0 || map.e == 0 || map.p > 1)
		error_handler(game, "CHARACHTERS NOT FOUND");
}

void	map_check(t_game *game)
{
	check_rect(game);
	check_surrend(game);
	check_characters(game);
}