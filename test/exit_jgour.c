#include "cub3D.h"

int	cub3d_exit(t_data *d)
{
	printf("END OF GAME\n");

	mlx_clear_window(d->mlx, d->win);
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	exit (0);
}