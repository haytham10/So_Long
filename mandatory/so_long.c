/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:16:56 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/08 22:02:31 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		f_error("INVALID NUMBER OF ARGUMENTS");
	if (f_check(av[1]) == 0)
		f_error("FILE NOT '.ber'");
	game.map = load_map(av[1]);
	if (game.map)
	{
		valid_map(&game);
		game_init(&game);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, game.win_w * 50,
				game.win_h * 50, "so_long");
		render_map(&game);
		mlx_hook(game.win, 2, (1L << 0), key_press, &game);
		mlx_hook(game.win, 17, (1L << 17), close_game, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
