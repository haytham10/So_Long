/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errooor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:43:17 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/05 17:18:08 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handler(t_game *game, char *msg)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	ft_putstr(msg);
	ft_putchar('\n');
	exit(1);
}

void	errooor(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(1);
}