/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:24:13 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/05 18:32:28 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0' && game->map[y][x + 1] == '0'
		&& game->map[y][x + 2] == '0')
	{
		game->enemies.sign = 0;
		game->enemies.x_enemy = x;
		game->enemies.y_enemy = y;
		return (1);
	}
	return (0);
}

int	enemy_pos(t_game *game)
{
	int	y;
	int	x;
	int	height;

	y = 0;
	height = get_height(game->map);
	if (game->enemies.sign)
	{
		while (y != height)
		{
			x = 0;
			while (game->map[y][x] != '\0')
			{
				if (check(game, x, y))
					return (1);
				x++;
			}
			y++;
		}
		return (0);
	}
	return (1);
}

void	open_door(t_game *game)
{
	int	y;
	int	x;
	int	height;
	int	img_w;
	int	img_h;

	y = 0;
	height = get_height(game->map);
	while (y != height)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'E')
			{
				game->img = mlx_xpm_file_to_image(game->mlx,
					"./imgs/open_exit.xpm", &img_w, &img_h);
				mlx_put_image_to_window(game->mlx, game->win, game->img,
					x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
}

void	use_door(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
}

void	load_text(t_game *game)
{
	int		img_w;
	int		img_h;
	char	*text;
	char	*num;

	num = ft_itoa(++game->movement);
	text = ft_strjoin("Steps: ", num);
	game->img = mlx_xpm_file_to_image(game->mlx,
		"./imgs/wall.xpm", &img_w, &img_h);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 50, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 100, 0);
	mlx_string_put(game->mlx, game->win, 5, 10, 0xFFFFFF, text);
	ft_putstr(num);
	ft_putchar('\n');
	free(text);
	free(num);
}