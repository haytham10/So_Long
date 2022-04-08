/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:21:13 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/08 21:37:08 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	e_check(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0' && game->map[y][x + 1] == '0' &&
		game->map[y][x + 2] == '0')
	{
		game->enemy.sign = 0;
		game->enemy.x = x;
		game->enemy.y = y;
		return (1);
	}
	return (0);
}

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
