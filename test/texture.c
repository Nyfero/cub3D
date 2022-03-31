#include "cub3D.h"

void	ft_put_img(t_data *d, void *image, int x, int y)
{
	mlx_put_image_to_window(d->mlx, d->win, image, x, y);
}

void	ft_creation_img(t_data *d)
{
	int	i;
	int	jt;

	jt = 5;
	i = 32;
	printf("i = %d\n", i);
	d->s = mlx_xpm_file_to_image(d->mlx, "./d_img/floor.xpm", &i, &i);
	d->w = mlx_xpm_file_to_image(d->mlx, "./d_img/wall.xpm", &i, &i);
	d->p = mlx_xpm_file_to_image(d->mlx, "./d_img/player.xpm", &jt, &jt);
	d->cdoor = mlx_xpm_file_to_image(d->mlx, "./d_img/cdoor.xpm", &jt, &jt);
	d->odoor = mlx_xpm_file_to_image(d->mlx, "./d_img/odoor.xpm", &jt, &jt);
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
		while (d->map.m[i][j] != 0)
		{
			if (d->map.m[i][j] == '1')
				ft_put_img(d, d->w, j * 32, i * 32);
			if (d->map.m[i][j] == '0')
				ft_put_img(d, d->s, j * 32, i * 32);
			if (d->map.m[i][j] == '2')
			{
				printf("close cdoor\n");
				ft_put_img(d, d->cdoor, j * 32, i * 32);

			}
			if (d->map.m[i][j] == '3')
			{
				printf("close odoor\n");
				ft_put_img(d, d->odoor, j * 32, i * 32);
			}
			j++;
		}
		j = 0;
		i++;
	//	printf("line j = %d size = %d\n", j, d->size);
	}
	//ft_put_img(d, d->p, (d->pl->xp * 5) - 2, (d->pl->yp  * 5) - 2);
	ft_put_img(d, d->p, d->pl->xp * -2 - 2, d->pl->yp * -2 - 2);
	//printf("end\n");
}