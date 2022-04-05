/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:29:26 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/31 14:47:43 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_window(t_game *game)
{
	int	i;

	i = 0;
	game->map_w = ft_strlen(game->map[0] * 50);
	while (game->map[i] != NULL)
		i++;
	game->map_h = i * 50;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		errooor("INVALID ARGUMENTS");
	if (file_check(av[1]) != 1)
		errooor("INVALID FILE");
	game.mlx = mlx_init();
	game.moves = 1;
	game.frame = 1;
	game.loop = 0;
	get_map(av[1], &game);
	game_window(&game);
	map_game(&game);
}