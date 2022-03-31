#include "cub3D.h"

void	ft_init_img2(t_wall *w, t_data *d)
{
	int	i;

	w->size = d->size;
	i = d->size;
	w->no.img = mlx_xpm_file_to_image(d->mlx, "./d_img/north_2.xpm", &i, &i);
	w->no.pixel = 0;
	w->no.line = 0;
	w->no.endian = 0;
	w->no.addr = (int *)mlx_get_data_addr(w->no.img, &w->no.pixel, &w->no.line, &w->no.endian);

	w->so.img = mlx_xpm_file_to_image(d->mlx, "./d_img/south_2.xpm", &i, &i);
	w->so.pixel = 0;
	w->so.line = 0;
	w->so.endian = 0;
	w->so.addr =(int *) mlx_get_data_addr(w->so.img, &w->so.pixel, &w->so.line, &w->so.endian);

	w->ea.img = mlx_xpm_file_to_image(d->mlx, "./d_img/east_2.xpm", &i, &i);
	w->ea.pixel = 0;
	w->ea.line = 0;
	w->ea.endian = 0;
	w->ea.addr = (int *)mlx_get_data_addr(w->ea.img, &w->ea.pixel, &w->ea.line, &w->ea.endian);

	w->we.img = mlx_xpm_file_to_image(d->mlx, "./d_img/weast_2.xpm", &i, &i);
	w->we.pixel = 0;
	w->we.line = 0;
	w->we.endian = 0;
	w->we.addr = (int *)mlx_get_data_addr(w->we.img, &w->we.pixel, &w->we.line, &w->we.endian);
}

void	ft_init_img1(t_wall *w, t_data *d)
{
	int	i;

	w->size = d->size;
	i = d->size;
	w->no.img = mlx_xpm_file_to_image(d->mlx, "./d_img/north_1.xpm", &i, &i);
	w->no.pixel = 0;
	w->no.line = 0;
	w->no.endian = 0;
	w->no.addr = (int *)mlx_get_data_addr(w->no.img, &w->no.pixel, &w->no.line, &w->no.endian);

	w->so.img = mlx_xpm_file_to_image(d->mlx, "./d_img/south_1.xpm", &i, &i);
	w->so.pixel = 0;
	w->so.line = 0;
	w->so.endian = 0;
	w->so.addr =(int *) mlx_get_data_addr(w->so.img, &w->so.pixel, &w->so.line, &w->so.endian);

	w->ea.img = mlx_xpm_file_to_image(d->mlx, "./d_img/east_1.xpm", &i, &i);
	w->ea.pixel = 0;
	w->ea.line = 0;
	w->ea.endian = 0;
	w->ea.addr = (int *)mlx_get_data_addr(w->ea.img, &w->ea.pixel, &w->ea.line, &w->ea.endian);

	w->we.img = mlx_xpm_file_to_image(d->mlx, "./d_img/weast_1.xpm", &i, &i);
	w->we.pixel = 0;
	w->we.line = 0;
	w->we.endian = 0;
	w->we.addr = (int *)mlx_get_data_addr(w->we.img, &w->we.pixel, &w->we.line, &w->we.endian);
}

void	ft_init_img(t_wall *w, t_data *d)
{
	int	i;

	w->size = d->size;
	i = d->size;
	w->no.img = mlx_xpm_file_to_image(d->mlx, "./d_img/north.xpm", &i, &i);
	w->no.pixel = 0;
	w->no.line = 0;
	w->no.endian = 0;
	w->no.addr = (int *)mlx_get_data_addr(w->no.img, &w->no.pixel, &w->no.line, &w->no.endian);

	w->so.img = mlx_xpm_file_to_image(d->mlx, "./d_img/south.xpm", &i, &i);
	w->so.pixel = 0;
	w->so.line = 0;
	w->so.endian = 0;
	w->so.addr =(int *) mlx_get_data_addr(w->so.img, &w->so.pixel, &w->so.line, &w->so.endian);

	w->ea.img = mlx_xpm_file_to_image(d->mlx, "./d_img/east.xpm", &i, &i);
	w->ea.pixel = 0;
	w->ea.line = 0;
	w->ea.endian = 0;
	w->ea.addr = (int *)mlx_get_data_addr(w->ea.img, &w->ea.pixel, &w->ea.line, &w->ea.endian);

	w->we.img = mlx_xpm_file_to_image(d->mlx, "./d_img/weast.xpm", &i, &i);
	w->we.pixel = 0;
	w->we.line = 0;
	w->we.endian = 0;
	w->we.addr = (int *)mlx_get_data_addr(w->we.img, &w->we.pixel, &w->we.line, &w->we.endian);

	d->big_img.img = mlx_new_image(d->mlx, 720, 720);
	d->big_img.pixel = 0;
	d->big_img.line = 0;
	d->big_img.endian = 0;
	d->big_img.addr= (int *)mlx_get_data_addr(d->big_img.img, &d->big_img.pixel, &d->big_img.line, &d->big_img.endian);

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
	t_wall		w0;
	t_wall		w1;
	t_wall		w2;
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
			d.map.m[i] = "1000121001";
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
	w0.fl = 0xFF0000;
	w1.fl = 0xFF0000;
	w2.fl = 0xFF0000;

	w0.cl = 0x48FF50;
	w1.cl = 0x48FF50;
	w2.cl = 0x48FF50;
	ft_init_img(&w0, &d);
	ft_init_img1(&w1, &d);
	ft_init_img2(&w2, &d);
	printf("coucou\n");
	d.wall = &w0;
	printf("coucou1 \n");
	w0.next = &w1;
	printf("coucou2 \n");
	w1.next = &w2;
	printf("coucou3 \n");
	w2.next = &w0;
	printf("coucou4 \n");
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
printf("UwU \n");
	ft_creation_img(&d);

printf("OwO \n");
	ft_affichage_map(&d);
printf("jsp \n");
	ft_game(d);

	return (0);
}