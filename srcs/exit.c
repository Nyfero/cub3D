#include "cub3D.h"

void	exit_before_exec(t_data *data)
{
	free_img(data);
	if (data->map.m)
		ft_free_ls(data->map.m);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	free_img(t_data *data)
{
	if (data->wall.no)
		mlx_destroy_image(data->mlx, data->wall.no);
	if (data->wall.so)
		mlx_destroy_image(data->mlx, data->wall.so);
	if (data->wall.we)
		mlx_destroy_image(data->mlx, data->wall.we);
	if (data->wall.ea)
		mlx_destroy_image(data->mlx, data->wall.ea);
}
