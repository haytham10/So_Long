/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:38:48 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/23 00:39:15 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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