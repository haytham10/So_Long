/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 01:16:27 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/06 02:11:00 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		*str = '\0';
		str++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)malloc(sizeof(char) * (count * size));
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (size * count));
	return (ptr);
}

void ft_putnbr(int n)
{
	unsigned int nb;
	if(n < 0)
	{
		nb = -n;
		ft_putchar ('-');
	}
	else
		nb = n;
	if(nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}