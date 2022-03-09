/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:38:06 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/09 16:25:36 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (!map)
		return (0);
	if (len < 5)
		return (0);
	if (map[len - 1] != 'r' || map[len - 2] != 'e' || map[len - 3] != 'b' || map[len - 4] != '.')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;
	
	if (ac != 2)
		death("INVALID NUMBER OF ARGUMENTS");
	if (map_check(av[1]) == 0)
		death("INVALID MAP ARGUMENT");
	data = data_init(av[1]);
	draw(data);
	mlx_hook(data->mlx_win, EVENT_KEY_PRESS, EVENT_KEY_PRESS_MASK, key_press, data);
	mlx_hook(data->mlx_win, EVENT_KEY_RELEASE, EVENT_KEY_RELEASE_MASK, key_release, data);
	mlx_hook(data->mlx_win, EVENT_CLOSE, EVENT_CLOSE_MASK, destroy_hook, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}