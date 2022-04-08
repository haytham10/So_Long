/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:11:33 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/08 21:46:56 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_press(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_UP)
		move_up(game);
	else if (key == KEY_S || key == KEY_DOWN)
		move_down(game);
	else if (key == KEY_A || key == KEY_LEFT)
		move_left(game);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_right(game);
	else if (key == KEY_ESC)
		game_over(game);
	return (0);
}
