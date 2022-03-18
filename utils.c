/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:51:11 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/18 21:54:10 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_line(int fd)
{
	char	*line;
	char	eol;
	int		len;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	eol = line[len - 1];
	if (eol == '\n')
		line[len - 1] = 0;
	return (line);
}

void	player_pos(t_game *game, t_list **objs, char *path, int cnt)
{
	t_list	*tmp;
	int		num;
	int		i;
	int		width;
	int		height;

	*objs = (t_list *)malloc(sizeof(t_list));
	tmp = *objs;
	i = 0;
	while (i < cnt)
	{
		num = '0' + i;
		tmp->img = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&width, &height);
		if (i != cnt - 1)
		{
			tmp->next = (t_list *)malloc(sizeof(t_list));
			tmp = tmp->next;
		}
		i++;
	}
	tmp->next = *objs;
}