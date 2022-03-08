#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "X.h"
#include "mlx_keys.h"
#include <mlx.h>

#define WIN_W 600
#define WIN_H 300

#define ERROR 1

#define RED 0xFF0000
#define GREEN 0xFF00
#define WHITE 0xFFFFFF

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

/* The x and y coordinates of the rect corresponds to its upper left corner. */

int	render_rect(t_img *img, t_rect rect)
{
	int	i = rect.y;
	while (i < rect.y + rect.height)
	{
		int	j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		data->mlx_win = NULL;
	}
	exit (0);
}

int	render(t_data *data)
{
	if(data->mlx_ptr == NULL)
		return (1);
	render_background(&data->img, 0x000000);
	render_rect(&data->img, (t_rect){WIN_W - 100, WIN_H - 100, 100, 100, RED});
	render_rect(&data->img, (t_rect){0, 0, 100, 100, GREEN});
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.mlx_img, 0, 0);
	return (0);
}

int	main()
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (ERROR);
	data.mlx_win = mlx_new_window(data.mlx_ptr, WIN_W, WIN_H, "1337");
	if (data.mlx_win == NULL)
	{
		free(data.mlx_win);
		return (ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIN_W, WIN_H);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &data);
	
	mlx_loop(data.mlx_ptr);
	free(data.mlx_ptr);

}

// int	main(void)
// {
// 	t_data	data;

// 	data.mlx_ptr = mlx_init();
// 	if (data.mlx_ptr == NULL)
// 		return (ERROR);
// 	data.mlx_win = mlx_new_window(data.mlx_ptr, WIN_W, WIN_H, "my window");
// 	if (data.mlx_win == NULL)
// 	{
// 		free(data.mlx_win);
// 		return (ERROR);
// 	}
// 	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIN_W, WIN_H);
// 	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
// 	mlx_loop_hook(data.mlx_ptr, &render, &data);
// 	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &data);
// 	mlx_loop(data.mlx_ptr);
// 	free(data.mlx_ptr);
// }