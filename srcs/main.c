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
	free_img(&data);
	ft_free_ls(data.map.m);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (0);
}
