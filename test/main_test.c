#include "cub3D.h"

void	ft_init_img(t_wall *w, t_data *d)
{
	int	i;

	w->size = d->size;
	i = d->size;
	w->no.img = mlx_xpm_file_to_image(d->mlx, "./d_img/north.xpm", &i, &i);
	w->so.img = mlx_xpm_file_to_image(d->mlx, "./d_img/south.xpm", &i, &i);
	w->ea.img = mlx_xpm_file_to_image(d->mlx, "./d_img/east.xpm", &i, &i);
	w->we.img = mlx_xpm_file_to_image(d->mlx, "./d_img/weast.xpm", &i, &i);

}

void	ft_init_player(t_player *player)
{	
	player->xp = 200;
	player->yp = 200;
	player->ap = PI/2;
	player->dxp = cos(player->ap) * MV;
	player->dyp = sin(player->ap) * MV;
}

int	main(void)
{
	t_data		d;
	t_wall		w;
	t_player	p;
	int			i;
	int			tempx;
	int			tempy;

	d.size = 64;
	d.h = 15;
	d.l = 10;
	d.map.m = malloc(sizeof(char *) * d.h);
	ft_init_player(&p);
	d.pl = &p;
	i = 0;
	while (i < d.h)
	{
		if (i == 0 || i == 14)
			d.map.m[i] = "1111111111";
		else if (i == 5)
			d.map.m[i] = "1000111001";
		else if (i == 6)
			d.map.m[i] = "1001000101";
		else
			d.map.m[i] = "1000000001";
		i++;
	}
	i = 0;
	while (i < d.h)
		printf("%s\n", d.map.m[i++]);
	
	d.mlx = mlx_init();
	if (d.mlx == 0)
		return (1);
	ft_init_img(&w, &d);
	d.wall = w;
	tempx = d.l * 32;
	tempy = d.h * 32;
	printf("temp x = %d\n", tempx);
	d.win = mlx_new_window(d.mlx, tempx, tempy, "cub2d");
	if (d.win == 0)
		exit (1);
	d.lwin = 720;
	d.hwin = 720;
	d.win3d = mlx_new_window(d.mlx, d.lwin, d.hwin, "cub3d");
	if (d.win3d == 0)
		exit (1);
	ft_creation_img(&d);
	ft_affichage_map(&d);
	ft_game(d);

	return (0);
}