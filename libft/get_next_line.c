/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:09:49 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/12 18:41:44 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char	buff[1];
	char	line[1000000];
	int		i;

	i = 0;
	line[0] = 0;
	if (fd < 0)
		return (NULL);
	while (read(fd, buff, 1) > 0)
	{
		line[i++] = buff[0];
		line[i] = 0;
		if (buff[0] == '\n')
			return (ft_strdup(line));
	}
	if (!line[0])
		return (NULL);
	return (ft_strdup(line));
}
