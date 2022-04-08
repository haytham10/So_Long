/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:21:13 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/08 21:30:20 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	f_check(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (!str)
		return (0);
	if (i < 5)
		return (0);
	if (str[i - 4] != '.' || str[i - 3] != 'b'
		|| str[i - 2] != 'e' || str[i - 1] != 'r')
		return (0);
	return (1);
}
