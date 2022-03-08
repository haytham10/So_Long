#include <stdlib.h>
#include "mlx.h"
#include "X.h"
#include "mlx_keys.h"

#define WIN_W	600
#define WIN_H	300

#define ERROR	1

#define GREEN	0x00ff00
#define	RED		0xff0000
#define	BLUE	0x0000ff

typedef struct rec_data
{
	int	x;
	int	y;
	int	width;
	int	height;
	int color;
}	r_data;

typedef	struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
}	t_data;

int	render_rect(t_data *data, r_data rec)
{
	int	i;
	int	j;

	if (data->mlx_ptr == NULL)
		return (ERROR);
	i = rec.y;
	while (i < rec.y + rec.height)
	{
		j = rec.x;
		while (j < rec.x + rec.width)
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, j++, i, rec.color);
		++i;
	}
	return (0);
}

int	handle_keys(int key, t_data *data)
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
	render_rect(data, (r_data){WIN_W - 100, WIN_H - 100, 100, 100, GREEN});
	// render_rect(data, (r_data){0, 0, 100, 100, RED});
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

	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &handle_keys, &data);
	// mlx_key_hook(data.mlx_win, &handle_keys, &data);
	mlx_loop(data.mlx_ptr);

	free(data.mlx_ptr);
}