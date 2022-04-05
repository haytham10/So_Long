/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:42:47 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/26 23:43:07 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	s1 = (char *)dest;
	s2 = (char *)src;
	if (dest > src)
	{
		i = n - 1;
		while (n--)
		{
			s1[i] = s2[i];
			i--;
		}
	}
	else if (dest < src)
		ft_memcpy(dest, src, n);
	return (dest);
}