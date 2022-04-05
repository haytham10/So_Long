/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:46:40 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/05 18:24:57 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_game *game)
{
	int	img_w;
	int	img_h;

	game->img = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->enemies.x_enemy * 50, game->enemies.y_enemy * 50);
	if (game->map[game->enemies.y_enemy][game->enemies.x_enemy + 1] != '1'
		&& game->map[game->enemies.y_enemy][game->enemies.x_enemy + 1] != 'E'
		&& game->map[game->enemies.y_enemy][game->enemies.x_enemy + 1] != 'C'
		&& game->enemies.move == 0)
		game->enemies.x_enemy++;
	else
		game->enemies.move = 1;
	if (game->map[game->enemies.y_enemy][game->enemies.x_enemy - 1] == '1'
		&& game->map[game->enemies.y_enemy][game->enemies.x_enemy - 1] != 'C'
		&& game->map[game->enemies.y_enemy][game->enemies.x_enemy - 1] != 'E'
		&& game->enemies.move == 1)
		game->enemies.x_enemy--;
	else
		game->enemies.move = 0;
}

static void	game_over(t_game *game, char *msg)
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
	exit(0);
}

void	render_img(t_game *game)
{
	int	i;
	int	j;

	game->enemies.imgs[0] = "./imgs/enemy0.xpm";
	game->enemies.imgs[1] = "./imgs/enemy1.xpm";
	game->enemies.imgs[2] = "./imgs/enemy2.xpm";
	game->enemies.imgs[3] = "./imgs/enemy3.xpm";
	game->enemies.imgs[4] = "./imgs/enemy4.xpm";
	game->enemies.imgs[5] = "./imgs/enemy5.xpm";
	game->enemies.imgs[6] = "./imgs/enemy6.xpm";
	game->enemies.imgs[7] = "./imgs/enemy7.xpm";
	game->img = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm", &i, &j);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->enemies.x_enemy * 50, game->enemies.y_enemy * 50);
	game->img = mlx_xpm_file_to_image (game->mlx, game->enemies.imgs[game->enemies.x], &i, &j);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->enemies.x_enemy * 50, game->enemies.y_enemy * 50);
}

int	animation(t_game *game)
{
	if (enemy_pos(game) != 0)
	{
		if (game->enemies.sleep-- <= 0)
		{
			game->enemies.x++;
			game->enemies.sleep = 5;
		}
		if (game->enemies.x == 3)
			game->enemies.x = 0;
		if (game->enemies.s_move-- <= 0)
		{
			move_enemy(game);
			game->enemies.s_move = 30;
		}
		if ((game->enemies.y_enemy == game->y_player / 50)
			&& (game->enemies.x_enemy == game->x_player / 50))
			game_over(game, "GAME OVER :(\n");
		render_img(game);
	}
	if (game->coll <= 0)
		open_door(game);
	return (0);
}