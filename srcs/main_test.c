#include "cub3D.h"

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
	t_player	p;
	int			i;
	int			tempx;
	int			tempy;

	d.size = 64;
	d.h = 15;
	d.l = 10;
	d.map = malloc(sizeof(char *) * d.h);
	ft_init_player(&p);
	d.pl = &p;
	i = 0;
	while (i < d.h)
	{
		if (i == 0 || i == 14)
			d.map[i] = "1111111111";
		else if (i == 5)
			d.map[i] = "1000111001";
		else if (i == 6)
			d.map[i] = "1001000101";
		else
			d.map[i] = "1000000001";
		i++;
	}
	i = 0;
	while (i < d.h)
		printf("%s\n", d.map[i++]);
	
	d.mlx = mlx_init();
	if (d.mlx == 0)
		return (1);
	tempx = d.l * d.size;
	tempy = d.h * d.size;
	printf("temp x = %d\n", tempx);
	d.win = mlx_new_window(d.mlx, tempx, tempy, "cub3d");
	if (d.win == 0)
		exit (1);
	d.win3d = mlx_new_window(d.mlx, 512, 512, "cub3d");
	if (d.win3d == 0)
		exit (1);
	ft_creation_img(&d);
	ft_affichage_map(&d);
	ft_game(d);

	return (0);
}