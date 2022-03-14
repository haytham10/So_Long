/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:45:49 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/14 16:45:57 by hmokhtar         ###   ########.fr       */
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