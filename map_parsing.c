/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:36:59 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/18 21:07:22 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (!map)
		return (0);
	if (len < 5)
		return (0);
	if (map[len - 1] != 'r' || map[len - 2] != 'e'
		|| map[len - 3] != 'b' || map[len - 4] != '.')
		return (0);
	return (1);
}

static void map_init(t_map *map, char *line)
{
	map->map = (char **)malloc(sizeof(char *) * 1);
	map->cols = ft_strlen(line);
	map->rows = 1;
	map->map[0] = line;
	map->c_player = 0;
	map->c_exit = 0;
	map->c_coll = 0;
}

void	read_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		death("ERORR OPENING MAP FILE");
	line = get_line(fd);
	map = &game->map;
	if (line)
		map_init(map, line);
	else
		death("EMPTY MAP FILE");
	line = get_line(fd);
	while (line)
	{
		valid_char(line);
		valid_len(line, game->map.cols);
		map->rows++;
		game->map.map = (char **)ft_realloc(game->map.map,
									map->rows - 1, map->rows);
		game->map.map[map->rows - 1] = line;
		line = get_line(fd);
	}
	close (fd);
}

void	count_objs(t_map *map)
{
	int		row_i;
	int		i;
	char	*row;

	row_i = 0;
	while (row_i < map->rows)
	{
		valid_wall(map, row_i);
		row = map->map[row_i];
		i = 0;
		while (i < map->cols)
		{
			if (row[i] == 'P')
				map->c_player++;
			else if (row[i] == 'E')
				map->c_exit++;
			else if (row[i] == 'C')
				map->c_coll++;
			i++;
		}
		row_i++;
	}
	valid_min(map);
}

void	map_parsing(t_game *game, char *filename)
{
	read_map(game, filename);
	count_objs(&game->map);
}