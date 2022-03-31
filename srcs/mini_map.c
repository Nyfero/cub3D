#include "cub3D.h"

void	short_pitw(t_data *d, void *img, int x, int y)
{
	mlx_put_image_to_window(d->mlx, d->win3d, img, x, y);
}

int	create_mini(t_data *data)
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

int	create_mini_bonus(t_data *data)
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

void	ft_mini_map_if(t_data *d, int y, int x)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (i < 2)
	{
		while (j < 2)
		{
			if (d->map[y + j][x + i] == '0')
				short_pitw(d, d->mmap.gr, (i + 1) * 64, (j + 1) * 64);
			if (d->map[y + j][x + i] == '1')
				short_pitw(d, d->mmap.wl, (i + 1) * 64, (j + 1) * 64);
			if (d->map[y + j][x + i] == '2')
				short_pitw(d, d->mmap.cdoor, (i + 1) * 64, (j + 1) * 64);
			if (d->map[y + j][x + i] == '3')
				short_pitw(d, d->mmap.odoor, (i + 1) * 64, (j + 1) * 64);
			j++;
		}
		j = -1;
		i++;
	}
}

void	ft_mini_map(t_data *d)
{
	int	x;
	int	y;

	y = (int)d->pl->yp / 64;
	x = (int)d->pl->xp / 64;
	ft_mini_map_if(d, y, x);
	mlx_put_image_to_window(d->mlx, d->win3d, d->mmap.pl,
		62 + (int)d->pl->xp % 64, 62 + (int)d->pl->yp % 64);
}
