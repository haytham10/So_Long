/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 23:39:44 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/26 22:59:47 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *buf, int b_size, int a_size)
{
	int		i;
	char	**src;
	char	**dst;

	src = (char **)buf;
	dst = (char **)malloc(sizeof(char *) * a_size);
	i = 0;
	while (i < b_size)
	{
		dst[i] = src[i];
		i++;
	}
	return ((void *)dst);
}
