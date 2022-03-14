/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_errors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:05:49 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/14 20:20:44 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f_errors(t_data *game)
{
	if (check_map1(game) == -1 || check_map2(game) == -1
		|| check_map3(game) == -1 || check_min(game) == -1
		|| check_square(game) == -1)
			death("INVALID MAP");
}