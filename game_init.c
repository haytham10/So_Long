/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:11:55 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/18 23:08:39 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_init(t_game *game)
{
	int	x;
	int	y;

	x = game->map.cols;
	y = game->map.rows;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr,
		x * 50, y * 50, "SO_LONG");
	game->move_status = 0;
	game->offset = 0;
	game->coll.coll = NULL;
	game->steps = 0;
}
void	imgs_init(t_game *game)
{
	t_objs		*objs;
	t_player	*player;
	int			width;
	int			height;

	objs = &game->objs;
	player = &game->player;
	objs->wall = mlx_xpm_file_to_image(game->mlx_ptr, "./imgs/wall.xpm",
		&width, &height);
	objs->floor = mlx_xpm_file_to_image(game->mlx_ptr, "./imgs/floor.xpm",
		&width, &height);
	objs->exit = mlx_xpm_file_to_image(game->mlx_ptr, "./imgs/exit.xpm",
		&width, &height);
	player_pos(game, &player->right_obj, "./imgs/player_right.xpm", 10);
	player_pos(game, &player->left_obj, "./imgs/player_left.xpm", 10);
	player_pos(game, &game->coll.obj, "./imgs/coll.xpm", 6);
	game->player.right_init = game->player.right_obj;
	game->player.left_init = game->player.left_obj;
	game->player.obj = game->player.right_obj;
	game->player.init = game->player.right_obj;
}

void	game_init(t_game *game)
{
	win_init(game);
	imgs_init(game);
	draw_map(game);
	draw_objs(game);
	draw_exit(game);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(EXIT_SUCCESS);
}