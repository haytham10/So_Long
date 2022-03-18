/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 23:39:44 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/18 23:40:02 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *buf, int before_size, int after_size)
{
	int		i;
	char	**src;
	char	**dst;

	src = (char **)buf;
	dst = (char **)malloc(sizeof(char *) * after_size);
	i = 0;
	while (i < before_size)
	{
		dst[i] = src[i];
		i++;
	}
	free(buf);
	return ((void *)dst);
}
