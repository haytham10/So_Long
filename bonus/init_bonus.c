/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:47:52 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/08 21:47:02 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_init(t_game *game)
{
	game->coll = 0;
	game->movement = 0;
	game->win_w = ft_strlen(game->map[0]);
	game->win_h = load_height(game->map);
	game->enemy.sign = 1;
	game->enemy.count = 0;
	game->enemy.move = 0;
	game->enemy.sleep = 5;
	game->enemy.s_move = 60;
}
