/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:02:14 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/26 23:02:41 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (!dest && !src)
		return (NULL);
	i = 0;
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}
