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
	printf("EXIT\n");
	exit_before_exec(&data);
	/*data.win = mlx_new_window(data.mlx, data.h * data.size, data.l * data.size, "map_cub3D");
	data.size_screen = 720;
	data.win3d = mlx_new_window(data.mlx, data.size_screen, data.size_screen, "cub3D");*/
	/*ft_creation_img(&data);
	ft_affichage_map(&data);*/
	/*ft_game(data);
	free_img(&data);
	ft_free_ls(data.map);
	mlx_destroy_display(data.mlx);
	free(data.mlx);*/
	return (0);
}

void	init_mouse(t_data *data)
{
	mlx_hook(data->win3d, 6, 1L << 6, &mouse_hook, data);
	mlx_mouse_hide(data->mlx, data->win3d);
	mlx_mouse_move(data->mlx, data->win3d, 700 * 0.5, 700 * 0.5);
}

int	mouse_hook(int mouse, t_data *data)
{
	(void)mouse;
	(void)data;
	/*if (mouse >=0 && mouse <= 200)
		ft_rotation(1, data->pl);
	else if (mouse >= 500 && mouse <= 700)
		ft_rotation(0, data->pl);*/
	//mlx_mouse_move(data->mlx, data->win3d, 700 * 0.5, 700 * 0.5);
	/*ft_affichage_map(data);
	ft_3d_render(data);*/
	return (0);
}

int	end_cub3d(t_data *data)
{
	free_img(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	ft_free_ls(data->map);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
