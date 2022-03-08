/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 21:49:09 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/03/06 01:12:10 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	d_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *) img->data + (x * img->bpp / 8 + y * img->len));
}

unsigned int	d_rgb_to_int(int o, int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*t;
	t = img->data + (x * img->bpp / 8 + y * img->len);
	*(unsigned int *)t = color;
}