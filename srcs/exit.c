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
	if (data->wall.no.img)
		mlx_destroy_image(data->mlx, data->wall.no.img);
	if (data->wall.so.img)
		mlx_destroy_image(data->mlx, data->wall.so.img);
	if (data->wall.we.img)
		mlx_destroy_image(data->mlx, data->wall.we.img);
	if (data->wall.ea.img)
		mlx_destroy_image(data->mlx, data->wall.ea.img);
}
