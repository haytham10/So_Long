// #include "so_long.h"
#include "mlx.h"
#include "mlx_keys.h"
#include "X.h"
#include <stdlib.h>
#include <unistd.h>

#define	ERROR	1

#define	RED		0xff0000
#define	GREEN	0x00ff00
#define	BLUE	0x0000ff

#define	WIN_W	500
#define	WIN_H	500

typedef	struct i_data
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	r_data;

typedef	struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef	struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		img_height;
	int		img_width;
	t_img	img;
}	t_data;

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	render_rect(t_img *img, r_data rect)
{
	int	i = rect.y;
	while (i < rect.y + rect.height)
	{
		int	j = rect.x;
		while (j < rect.x + rect.width)
			img_pixel_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_backgroud(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
			img_pixel_put(img, j++, i, color);
		++i;
	}
}

int	handle_keys(t_data *data, int key)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		data->mlx_ptr = NULL;
	}
	exit (0);
}

int	render(t_data *data)
{
	if (data->mlx_ptr == NULL)
		return (ERROR);
	render_backgroud(&data->img, 0x000000);
	render_rect(&data->img, (r_data){WIN_W - 100, WIN_H - 100, 100, 100, RED});
	render_rect(&data->img, (r_data){0, 0, 100, 100, GREEN});
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.mlx_img, 0, 0);
	return (0);
}

int	main()
{
	t_data	data;
	int		m_hide;

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
	// data.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, "500x500.xpm", &data.img_width, &data.img_height);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &handle_keys, &data);

	mlx_loop(data.mlx_ptr);
	free(data.mlx_ptr);

}

