/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:33:35 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/05 15:31:04 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_line(char *line, int fd)
{
	char	*tmp;
	int		i;
	
	i = 0;
	while (get_next_line(fd, &tmp) == 1)
	{
		if (i == 0)
			line = ft_strdup(tmp);
		else
			line = ft_strjoin(line, tmp);
		i++;
		free(tmp);
	}
	return (line);
}

void	get_map(char *av, t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;

	line = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
	tmp = get_line(line, fd);
	if (!tmp)
		exit(1);
	if (tmp[ft_strlen(tmp) - 1] == '\n')
		errooor("INVALID MAP");
	game->map = ft_split(tmp, '\n');
	if (game->map)
		exit(1);
	free(tmp);
	close(fd);
}
