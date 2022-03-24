#include "cub3D.h"

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