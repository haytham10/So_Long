/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:43:13 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/14 16:43:22 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (!map)
		return (0);
	if (len < 5)
		return (0);
	if (map[len - 1] != 'r' || map[len - 2] != 'e' || map[len - 3] != 'b' || map[len - 4] != '.')
		return (0);
	return (1);
}