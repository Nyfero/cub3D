#include "cub3D.h"

void	ft_check_vertical_right(t_data *d, t_player *pl, t_check *v)
{
	v->rx = (((int)pl->xp / d->size) * d->size) + d->size;
	v->ry = (pl->xp - v->rx) * -tan(pl->ap) + pl->yp;
	v->xo = d->size;
	v->yo = -v->xo * -tan(pl->ap);
}

void	ft_check_vertical_left(t_data *d, t_player *pl, t_check *v)
{
	v->rx = (((int)pl->xp / d->size) * d->size) - 0.0001;
	v->ry = (pl->xp - v->rx) * -tan(pl->ap) + pl->yp;
	v->xo = -1 * d->size;
	v->yo = -v->xo * -tan(pl->ap);
}

void	ft_check_vertical_up_down(t_data *d, t_player *pl, t_check *v, int *dof)
{
	v->rx = pl->xp;
	v->ry = pl->yp;
	*dof = d->l;
}

void	ft_check_vertical_next(t_check *v, int	*dof)
{
	v->rx += v->xo;
	v->ry += v->yo;
	*dof = *dof + 1;
}


float	ft_check_vertical(t_data *d, t_player *pl)
{
	int		mx;
	int		my;
	int		dof;
	t_check	v;

	dof = 0;
	if (pl->ap < P2 || pl->ap > P3)//looking left
		ft_check_vertical_left(d, pl, &v);
	if (pl->ap > P2 && pl->ap < P3)//looking right
		ft_check_vertical_right(d, pl, &v);
	if (!pl->ap || pl->ap == PI)//looking up / down
		ft_check_vertical_up_down(d, pl, &v, &dof);
	while (dof < d->l)
	{
		mx = (int)v.rx / d->size;		//pos x de la map
		my = (int)v.ry / d->size;		//pos y de la map
		if ((my >= 0 && mx >= 0 && my < d->h && mx < d->l) && d->map[my][mx] == '1')	//wall hit
		{
			// printf("map[%d][%d] estun wall\n", mx, my);
			  for (int test = 16; test< 32; test++)
			  	for (int test2 = 16; test2< 32; test2++)
			  		mlx_pixel_put(d->mlx, d->win, mx *64 + test, my * 64 + test2, 0xFF0000);
			return (ft_dist(pl->xp, pl->yp, v.rx, v.ry));
		}
		else if (my < 0 || my < 0 || my > d->h || mx > d->l)
			dof = d->l;
		else	//next line
			ft_check_vertical_next(&v, &dof);
	}
	return (-1);
}



/*
void	ft_check_vertical(t_data *d, t_player *pl)
{
	int		mx,my,dof;
	float	rx, ry, ra, xo, yo;
	float	ntan;
	float	disV = 1000000;
	float	vx = pl->xp;
	float	vy = pl->yp;

	ra = pl->ap;
//	while (r < 1)//nombre de ray caster
//	{
		dof = 0;
		ntan = -tan(ra);
//		r++;
		if (ra < P2 || ra > P3)//looking left
		{
			rx = (((int)pl->xp / d->size) * d->size) - 0.0001;
			ry = (pl->xp - rx) * ntan + pl->yp;
			xo = -1 * d->size;
			yo = -xo * ntan;
		}
		if (ra > P2 && ra < P3)//looking right
		{
			rx = (((int)pl->xp / d->size) * d->size) + d->size;
			ry = (pl->xp - rx) * ntan + pl->yp;
			xo = d->size;
			yo = -xo * ntan;
		}
		if (!ra || ra == PI)//looking up / down
		{
			rx = pl->xp;
			ry = pl->yp;
			dof = d->l;
		}
		while (dof < d->l)
		{
			mx = (int)rx / d->size;		//pos x de la map
			my = (int)ry / d->size;		//pos y de la map
			
		//	printf("d->l=%d ||d->%d\n", d->l,d->h);
		//	printf("rx=%.1f ||ry=%.1f ||mx=%d ||my=%d\n", rx, ry, mx, my);
			if ((my >= 0 && mx >= 0 && my < d->h && mx < d->l) && d->map[my][mx] == '1')	//wall hit
			{
				vx = rx;
				vy = ry;
				disV = ft_dist(pl->xp, pl->yp, vx, vy);
				printf("map[%d][%d] estun wall\n", mx, my);
				
					for (int test = 16; test< 32; test++)
						for (int test2 = 16; test2< 32; test2++)
							mlx_pixel_put(d->mlx, d->win, mx *64 + test, my * 64 + test2, 0xFF0000);
				
				dof = d->l;

			}
			else	//next line
			{
				if (my < 0 ||my < 0 || my > d->h || mx > d->l)
					dof = d->l;
				rx += xo;
				ry += yo;
				dof++;
			}
		// i = -1;
		// j = -1;
		// 	while (i < 2)
		// 	{
		// 		while (j < 2)
		// 		{
		// 			mlx_pixel_put(d->mlx, d->win, j + (mx * d->size), i + my * d->size, 0xFF0000);
		// 			for(int test = 0; test < d->size; test++)
		// 				mlx_pixel_put(d->mlx, d->win, j + (mx * d->size), i + my * d->size + test, 0xFF0000);
		// 			j++;
		// 		}
		// 		j = -2;
		// 		i++;
		// 	}
		}
		//printf("alpha 7\n");
//	}
}
*/