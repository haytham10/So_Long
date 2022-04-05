/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:48:54 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/04 20:32:35 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] != 'P' && game->map[i][j] != 'E'
				&& game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'F' && game->map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
