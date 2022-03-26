#include "cub3D.h"

void	exit_before_exec(t_data *data)
{
	free_img(data);
	ft_free_ls(data->map.m);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	free_img(t_data *data)
{
	if (data->wall.no.i)
		mlx_destroy_image(data->mlx, data->wall.no.i);
	if (data->wall.so.i)
		mlx_destroy_image(data->mlx, data->wall.so.i);
	if (data->wall.we.i)
		mlx_destroy_image(data->mlx, data->wall.we.i);
	if (data->wall.ea.i)
		mlx_destroy_image(data->mlx, data->wall.ea.i);
}
