#include "cub3D.h"

int	create_mini_map(t_data *data)
{
	int	size_player;

	size_player = 5;
	data->mmap.size_map = 32;
	data->mmap.gr = mlx_xpm_file_to_image(data->mlx, "./d_img/floor.xpm",
			&data->mmap.size_map, &data->mmap.size_map);
	data->mmap.wl = mlx_xpm_file_to_image(data->mlx, "./d_img/wall.xpm",
			&data->mmap.size_map, &data->mmap.size_map);
	data->mmap.pl = mlx_xpm_file_to_image(data->mlx, "./d_img/player.xpm",
			&size_player, &size_player);
	if (!data->mmap.gr || !data->mmap.wl || !data->mmap.pl)
		return (1);
	return (0);
}

int	create_mini_map_bonus(t_data *data)
{
	int	size_player;

	size_player = 5;
	data->mmap.size_map = 32;
	data->mmap.gr = mlx_xpm_file_to_image(data->mlx, "./d_img/floor.xpm",
			&data->mmap.size_map, &data->mmap.size_map);
	data->mmap.wl = mlx_xpm_file_to_image(data->mlx, "./d_img/wall.xpm",
			&data->mmap.size_map, &data->mmap.size_map);
	data->mmap.pl = mlx_xpm_file_to_image(data->mlx, "./d_img/player.xpm",
			&size_player, &size_player);
	data->mmap.cdoor = mlx_xpm_file_to_image(data->mlx, "./d_img/cdoor.xpm",
			&data->mmap.size_map, &data->mmap.size_map);
	data->mmap.odoor = mlx_xpm_file_to_image(data->mlx, "./d_img/odoor.xpm",
			&data->mmap.size_map, &data->mmap.size_map);
	if (!data->mmap.gr || !data->mmap.wl || !data->mmap.pl
		|| !data->mmap.cdoor || !data->mmap.odoor)
		return (1);
	return (0);
}

void	ft_mini_map(t_data *d)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	j = -1;
	y = (int)d->pl->yp / 64;
	x = (int)d->pl->xp / 64;
	printf("x=%d |y=%d|\n",x , y);
	while (i < 2)
	{
		while (j < 2)
		{
			// printf("x=%d |y=%d|rx=%d|ry=%d\n",x , y, x + i);
			if (d->map.m[y + j][x + i] == '0')
				mlx_put_image_to_window(d->mlx, d->win3d, d->s, (i + 1) * 64, (j + 1) * 64);
			if (d->map.m[y + j][x + i] == '1')
				mlx_put_image_to_window(d->mlx, d->win3d, d->w, (i + 1) * 64, (j + 1) * 64);
			if (d->map.m[y + j][x + i] == '2')
				mlx_put_image_to_window(d->mlx, d->win3d, d->cdoor, (i + 1) * 64, (j + 1) * 64);
		printf("ici \n");
			if (d->map.m[y + j][x + i] == '3')
				mlx_put_image_to_window(d->mlx, d->win3d, d->odoor, (i + 1) * 64, (j + 1) * 64);
		printf("bas \n");
			j++;
		}
		j = -1;
		i++;
	}
	mlx_put_image_to_window(d->mlx, d->win3d, d->p, 62 + (int)d->pl->xp % 64, 62 + (int)d->pl->yp % 64);
}
