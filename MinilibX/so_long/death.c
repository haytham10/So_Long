/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:23:21 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/05 21:04:35 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	death(char *msg)
{
	if (msg != 0)
	{
		ft_putstr(msg);
		ft_putchar('\n');
		exit (1);
	}
	exit (0);
}