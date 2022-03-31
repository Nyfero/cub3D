#include "cub3D.h"

void	ft_rotation(int nb, t_player *p)
{
	if (nb == 1)//gauche
	{
		p->ap -= 0.1;
		if (p->ap < 0)
			p->ap += 2*PI;
	}
	else //droite
	{
		p->ap += 0.1;
		if (p->ap > 2 * PI)
			p->ap -= 2 * PI;
	}
	// printf("ra = %f\n", p->ap);
	p->dxp = (cos(p->ap) * MV);
	p->dyp = (sin(p->ap) * MV);
}

void	ft_deplacement_hor(t_data *d, int nb, t_player *p)
{
	float	temp_a;
	float	temp_x;
	float	temp_y;
	if (nb > 0)//d
	{
		temp_a = p->ap + PI / 2;
		if (temp_a > 2 * PI)
			temp_a -= 2 * PI;
		temp_x = cos(temp_a) * MV;
		temp_y = sin(temp_a) * MV;
		if (!ft_check_deplacement(d, p, temp_x, temp_y))
		{
			p->xp -=  temp_x;
			p->yp -=  temp_y;
		}
	}
	else//a
	{
		temp_a = p->ap - PI / 2;
		if (temp_a < 0)
			temp_a += 2 * PI;
		temp_x = cos(temp_a) * MV;
		temp_y = sin(temp_a) * MV;
		if (!ft_check_deplacement(d, p, temp_x, temp_y))
		{	
			p->xp -=  temp_x;
			p->yp -=  temp_y;
		}
	}
}

void	ft_deplacement_vert(t_data *d, int nb, t_player *p)
{
	if (nb > 0)//s
	{
		if (!ft_check_deplacement_2(d, p))
		{
			p->xp +=  p->dxp;
			p->yp +=  p->dyp;
		}
	}
	else//	w
	{
		if (!ft_check_deplacement(d, p, p->dxp, p->dyp))
		{
			p->xp -=  p->dxp;
			p->yp -=  p->dyp;
		}
	}
}

int	ft_game_event(int key, t_data *d)
{
	if (key == 65307)
		cub3d_exit(d);
	if (key == 65361)
		ft_rotation(1, d->pl);
	if (key == 65363)
		ft_rotation(-1, d->pl);
	if (key == 119)
		ft_deplacement_vert(d, -1, d->pl);
	if (key == 97)
		ft_deplacement_hor(d, -1, d->pl);
	if (key == 115)
		ft_deplacement_vert(d, 1, d->pl);
	if (key == 100)
		ft_deplacement_hor(d, 1, d->pl);
	if (key == 65307 || key == 65361 || key == 65363 || key == 119 || key == 97
		|| key == 115 || key == 100)
	{
		ft_affichage_map(d);
		ft_3d_render(d);
		if (d->wall->next)
			d->wall = d->wall->next;
	}
	return (0);
}

int	ft_game(t_data d)
{
	ft_3d_render(&d);
	mlx_hook(d.win3d, 02, (1L<<0), ft_game_event, &d);
	mlx_hook(d.win3d, 33, 1L << 5, cub3d_exit, &d);//exit croix
	mlx_loop(d.mlx);
	return (0);
}
