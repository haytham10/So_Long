/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:50:23 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/05 22:41:25 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_check(char *map)
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

int	get_height(char **map)
{
	int		i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**get_map(char *fileName)
{
	char	*line;
	char	*all_lines;
	int		i;
	int		fd;

	i = 0;
	line =  "";
	all_lines = ft_strdup("");
	fd = open(fileName, O_RDONLY);
	if (fd == -1)
		errooor("ERROR OPENING FILE");
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	if (all_lines[0] == '\0')
		errooor("INVALID MAP");
	return (ft_split(all_lines, '\n'));
}