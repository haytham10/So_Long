/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:26:43 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/04/08 22:14:58 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_steps(t_game *game)
{
	int		w;
	int		h;
	char	*text;
	char	*num;

	num = ft_itoa(++game->movement);
	text = ft_strjoin("Steps: ", num);
	game->img = mlx_xpm_file_to_image(game->mlx, "../assets/wall.xpm", &w, &h);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 50, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 100, 0);
	mlx_string_put(game->mlx, game->win, 5, 10, 0xFFFFFF, text);
	ft_putstr(text);
	ft_putchar('\n');
	free(text);
	free(num);
}

void	load_img(t_game *game, char *img, int x, int y)
{
	int	width;
	int	height;

	game->img = mlx_xpm_file_to_image(game->mlx, img, &width, &height);
	mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);
}

void	load_texture(t_game *game, char obj, int x, int y)
{
	if (obj == '1')
		load_img(game, "../assets/wall.xpm", x, y);
	else if (obj == 'E')
	{
		load_img(game, "../assets/floor.xpm", x, y);
		load_img(game, "../assets/exit.xpm", x, y);
	}
	else if (obj == 'C')
	{
		load_img(game, "../assets/floor.xpm", x, y);
		load_img(game, "../assets/coll.xpm", x, y);
		game->coll++;
	}
	else if (obj == 'P')
	{
		game->y_player = y;
		game->x_player = x;
		load_img(game, "../assets/floor.xpm", x, y);
		load_img(game, "../assets/rsonic.xpm", x, y);
	}
	else
		load_img(game, "../assets/floor.xpm", x, y);
}

int	load_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**load_map(char *file)
{
	int		fd;
	char	*line;
	char	*map;
	int		i;

	i = 0;
	line = "";
	map = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		f_error("ERROR OPENING FILE");
	while (line)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\0')
			break ;
		map = ft_strjoin(map, line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	if (map[0] == '\0')
		f_error("EMPTY FILE");
	return (ft_split(map, '\n'));
}
