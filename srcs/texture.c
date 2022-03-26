#include "cub3D.h"
/*
void	ft_bordure_propre(t_data d)
{
	int	i;
	int	temp;
	int	coord;

	temp = -1;
	i = -1;
	coord = d.map.h_max * d.t;
	while (++i < d.map.lg * d.t)
	{
		temp = -1;
		while (++temp < 2)
			mlx_pixel_put(d.mlx, d.win, i, coord - temp, 0x00FFFFFF);
	}
	i = -1;
	coord = d.map.lg * d.t;
	while (++i < d.map.h_max * d.t)
	{
		temp = -1;
		while (++temp < 2)
			mlx_pixel_put(d.mlx, d.win, coord - temp, i, 0x00FFFFFF);
	}
}

void	ft_texture(int x, int y, t_data d, int couleur)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < d.t)
	{
		while (j < d.t)
		{
			if ((i < d.t / 5 || j < d.t / 5) && (i < 2 || j < 2))
				mlx_pixel_put(d.mlx, d.win, i + x, j + y, 0xFFFFFFFF);
			else
				mlx_pixel_put(d.mlx, d.win, i + x, y + j, couleur);
			j++;
		}
		i++;
		j = 0;
	}
}*/

void	ft_put_img(t_data *d, void *image, int x, int y)
{
	mlx_put_image_to_window(d->mlx, d->win, image, x, y);
}

void	ft_creation_img(t_data *d)
{
	int	i;
	int	jt;

	jt = 5;
	i = d->size;
	printf("i = %d\n", i);
	d->s = mlx_xpm_file_to_image(d->mlx, "./d_img/floor.xpm", &i, &i);
	d->w = mlx_xpm_file_to_image(d->mlx, "./d_img/wall.xpm", &i, &i);
	d->p = mlx_xpm_file_to_image(d->mlx, "./d_img/player.xpm", &jt, &jt);
	if (d->s == 0 || d->w == 0 || d->p == 0)
		cub3d_exit(d);
}

void	ft_affichage_map(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < d->h)
	{
		while (d->map[i][j] != 0)
		{
			if (d->map[i][j])
				ft_put_img(d, d->w, j * d->size, i * d->size);
			if (d->map[i][j] == '0')
				ft_put_img(d, d->s, j * d->size, i * d->size);
			j++;
		}
		j = 0;
		i++;
	//	printf("line j = %d size = %d\n", j, d->size);
	}
	//ft_put_img(d, d->p, (d->pl->xp * 5) - 2, (d->pl->yp  * 5) - 2);
	ft_put_img(d, d->p, d->pl->xp - 2, d->pl->yp - 2);
	//printf("end\n");
}