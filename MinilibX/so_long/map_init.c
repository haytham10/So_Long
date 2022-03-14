/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:45:51 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/13 15:01:37 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void parsing(t_data *data, char **file, char buff[], int fd)
{
	char	*tmp;

	tmp = ft_strjoin(*file, buff);
	free(*file);
	*file = tmp;
	if (*file == 0)
	{
		close (fd);
		destroyer(data, "map_init/ft_strjoin");
	}
}

static void	file_read(t_data *data, char **file, char buff[], int fd)
{
	int	ret;

	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buff, 1024);
		if (ret == -1)
		{
			free(*file);
			close(fd);
			destroyer(data, "map_init/read");
		}
		else
		{
			buff[ret] = 0;
			parsing(data, file, buff, fd);
		}
	}
}

static char *file_init(t_data *data, int fd)
{
	char	*file;
	
	file = ft_calloc(1, 1);
	if (file == 0)
	{
		close(fd);
		destroyer(data, "map_init/ft_calloc");
	}
	return (file);
}

void	map_init(t_data *data, char *name)
{
	int		fd;
	char	*file;
	char	buff[1024];

	fd = open(name, O_RDONLY);
	if (fd == -1)
		destroyer(data, name);
	file = file_init(data, fd);
	file_read(data, &file, buff, fd);
	close(fd);
	map_read(data, file);
	free(file);
}