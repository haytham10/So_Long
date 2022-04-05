/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:57:55 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/05 22:50:21 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_game *game, int x, int y, char *img)
{
	int		i;
	int		j;

	game->img = mlx_xpm_file_to_image(game->mlx, img, &i, &j);
	mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);
}

void	load_texture(char p, int x, int y, t_game *game)
{
	if (p == '1')
		load_img(game, x, y, "./imgs/wall.xpm");
	else if (p == 'C')
	{
		load_img(game, x, y, "./imgs/floor.xpm");
		load_img(game, x, y, "./imgs/coll.xpm");
		game->coll++;
	}
	else if (p == 'E')
		load_img(game, x, y, "./imgs/exit.xpm");
	else if (p == 'P')
	{
		game->x_player = x;
		game->y_player = y;
		load_img(game, x, y, "./imgs/floor.xpm");
		load_img(game, x, y, "./imgs/fsonic.xpm");
	}
	else
		load_img(game, x, y, "./imgs/floor.xpm");
}