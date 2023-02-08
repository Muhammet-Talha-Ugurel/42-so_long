
#include "../lib/mlx_lib/mlx.h"
#include "../include/so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>


int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->win);
	if (keysym == 119)
		move_character(data, 1);
	if (keysym == 115)
		move_character(data, 2);
	if (keysym == 100)
		move_character(data, 3);
	if (keysym == 97)
		move_character(data, 4);
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

void move_character(t_data *data, int d)
{
	if (d == 1)
	{
		mlx_clear_window(data->mlx, data->win);
		data->y -= 64;
		mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
	}
	else if (d == 2)
	{
		mlx_clear_window(data->mlx, data->win);
		data->y += 64;
		mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
	}
	else if (d == 3)
	{
		mlx_clear_window(data->mlx, data->win);
		data->x += 64;
		mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
	}
	else if (d == 4)
	{
		mlx_clear_window(data->mlx, data->win);
		data->x -= 64;
		mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
	}
}

void	read_map(t_data *data, char *name)
{
}

int	main(int ac, char **av)
{
	t_data	data;

	reaad_map
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1366, 400, "MTU");
	data.path = "./xpms/player/player.xpm";
	data.img = mlx_xpm_file_to_image(data.mlx, data.path,	&data.img_width, &data.img_height);
	data.x = 0;
	data.y = 0;
	mlx_put_image_to_window(data.mlx, data.win, data.img, data.x, data.y);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (0);
}
