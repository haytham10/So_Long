/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:09:49 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/28 21:09:51 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	int i = 0;
	char	*s2;

	while (s1[i])
		i++;
	s2 = malloc(i + 1);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return s2;
}

char	*get_next_line(int fd)
{
	char	buff[1];
	char	line[1000000];
	int		i = 0;

	line[0] = 0;
	if (fd < 0)
		return NULL;
	while (read(fd, buff, 1) > 0)
	{
		line[i++] = buff[0];
		line[i] = 0;
		if (buff[0] == '\n')
			return ft_strdup(line);
	}
	if (!line[0])
		return (NULL);
	return ft_strdup(line);
}
