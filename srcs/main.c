#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv))
		return (1);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (2);
	if (parsing(&data, argv[1]))
	{
		exit_before_exec(&data);
		return (3);
	}
	data.win = mlx_new_window(data.mlx, 1920, 1080, "cub3D");
	init_mouse(&data);
	mlx_hook(data.win, 33, 1L << 5, end_cub3d, &data);
	mlx_loop(data.mlx);
	free_img(&data);
	ft_free_ls(data.map.m);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (0);
}

void	init_mouse(t_data *data)
{
	mlx_hook(data->win, 6, 1L << 6, &mouse_hook, data);
	mlx_mouse_hide(data->mlx, data->win);
	mlx_mouse_move(data->mlx, data->win, 1920 * 0.5, 1080 * 0.5);
}

int	mouse_hook(int mouse, t_data *data)
{
	printf("key:%d\n", mouse);
	(void)data;
	return (0);
}

int	end_cub3d(t_data *data)
{
	free_img(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	ft_free_ls(data->map.m);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
