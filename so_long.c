/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:09:43 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/18 23:25:53 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		death("INVALID ARGUMENTS");
	if (map_check(av[1]) != 1)
		death("INVALID MAP FILE");
	map_parsing(&game, av[1]);
	game_init(&game);
	mlx_hook(game.win_ptr, 17, 0, &close_game, &game);
	mlx_key_hook(game.win_ptr, &key_hook, &game);
	mlx_loop_hook(game.mlx_ptr, &loop_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}