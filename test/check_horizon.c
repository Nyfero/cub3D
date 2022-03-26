#include "cub3D.h"

void	ft_check_horizontal_up(t_data *d, t_player *pl, t_check *v)
{
	v->ry = (((int)pl->yp / d->size) * d->size) - 0.0001;
	v->rx = (pl->yp - v->ry) * (-1 / tan(pl->ap)) + pl->xp;
	v->yo = -d->size;
	v->xo = -v->yo * (-1 / tan(pl->ap));
}

void	ft_check_horizontal_down(t_data *d, t_player *pl, t_check *v)
{
	v->ry = (((int)pl->yp / d->size) * d->size) + d->size;
	v->rx = (pl->yp - v->ry) * (-1 / tan(pl->ap)) + pl->xp;
	v->yo = d->size;
	v->xo = -v->yo * (-1 / tan(pl->ap));
}

void	ft_check_horizontal_l_r(t_data *d, t_player *pl, t_check *v, int *dof)
{
	v->rx = pl->xp;
	v->ry = pl->yp;
	*dof = d->h;
}

void	ft_check_horizontal_next(t_check *v, int *dof)
{
	v->rx += v->xo;
	v->ry += v->yo;
	*dof = *dof + 1;
}

float	ft_check_horizontal(t_data *d, t_player *pl)
{
	int		mx;
	int		my;
	int		dof;
	t_check	v;

	dof = 0;
	if (pl->ap < PI)//looking up
		ft_check_horizontal_up(d, pl, &v);
	if (pl->ap > PI)//looking down
		ft_check_horizontal_down(d, pl, &v);
	if (!pl->ap || pl->ap == PI)
		ft_check_horizontal_l_r(d, pl, &v, &dof);
	while (dof < d->h)
	{
		mx = (int)v.rx / d->size;		//pos x de la map
		my = (int)v.ry / d->size;		//pos y de la map
		if ((my >= 0 && mx >= 0 && my < d->h && mx < d->l) && d->map[my][mx] == '1')	//wall hit
		{
			for (int test = 0; test< 64; test++)
				for (int test2 = 0; test2< 64; test2++)
					mlx_pixel_put(d->mlx, d->win, mx *64 + test, my * 64 + test2, 0x5B034F);
			return (ft_dist(pl->xp, pl->yp, v.rx, v.ry));
		}
		else if (my < 0 ||my < 0 || my > d->h || mx > d->l)
			dof = d->h;
		else		//next line
			ft_check_horizontal_next(&v, &dof);
	}
	return (-1);
}



/*
void	ft_check_horizontal(t_data *d, t_player *pl)
{
	int		mx,my,dof;
	float	rx, ry, ra, xo, yo;
	float	atan;
	float	disH = 1000000;
	float	hx = pl->xp;
	float	hy = pl->yp;

	ra = pl->ap;
	//while (r < 1)//nombre de ray caster
	//{
		dof = 0;
		atan = -1 / tan(ra);
	//	r++;
		if (ra < PI)//looking up
		{
			ry = (((int)pl->yp / d->size) * d->size) - 0.0001;
			rx = (pl->yp - ry) * atan + pl->xp;
			yo = -d->size;
			xo = -yo * atan;
		}
		if (ra > PI)//looking down
		{
			ry = (((int)pl->yp / d->size) * d->size) + d->size;
			rx = (pl->yp - ry) * atan + pl->xp;
			yo = d->size;
			xo = -yo * atan;
		}
		if (!ra || ra == PI)
		{
			rx = pl->xp;
			ry = pl->yp;
			dof = d->h;
		}
		while (dof < d->h)
		{
			mx = (int)rx / d->size;		//pos x de la map
			my = (int)ry / d->size;		//pos y de la map
		//	printf("rx=%.1f ||ry=%.1f ||mx=%d ||my=%d\n", rx, ry, mx, my);
			if ((my >= 0 && mx >= 0 && my < d->h && mx < d->l) && d->map[my][mx] == '1')	//wall hit
			{
				hx = rx;
				hy = ry;
				disH = ft_dist(pl->xp, pl->yp, hx, hy);
				dof = d->h;
				for (int test = 0; test< 64; test++)
					for (int test2 = 0; test2< 64; test2++)
						mlx_pixel_put(d->mlx, d->win, mx *64 + test, my * 64 + test2, 0x5B034F);
			}
			else						//next line
			{
				if (my < 0 ||my < 0 || my > d->h || mx > d->l)
					dof = d->h;
				rx += xo;
				ry += yo;
				dof++;
			}

		}
	//}
}*/