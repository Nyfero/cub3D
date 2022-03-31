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
	end_cub3d(&data);
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
