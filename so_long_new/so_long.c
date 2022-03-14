/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:40:36 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/14 20:24:24 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_map(char **av)
{
	int		fd;
	int		line;
	char	*str;

	fd = open(av[1], O_RDONLY);
	line = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free (str);
		line++;
	}
	close(fd);
	retrun (line);
}

static void	read_map(t_data *game, char **av)
{
	int		fd;
	int		line;
	char	*str;

	line = count_map(av);
	fd = open(av[1], O_RDONLY);
	game->map.map = (char **)malloc(line * sizeof(char *));
	line = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		game->map.map[line] = str;
		line++;
	}
	close(fd);
	game->img_height = line;
	game->img_width = ft_strlen(game->map.map[0]);
}

int	main(int ac, char **av)
{
	t_data	*game;

	if (ac != 2)
		death("INVALID NUMBER OF ARGUMENTS");
	if (map_check(av[1]) == 0)
		death("INVALID MAP ARGUMENT");
	read_map(game, av);
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->img_width * 100,
			game->img_height * 100, "so_long");
	f_errors(game);
	img_init(game);
}