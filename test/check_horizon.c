#include "cub3D.h"

void	ft_check_horizontal_up(t_data *d, t_player *pl, t_check *v, float ra)
{
	v->ry = (((int)pl->yp / d->size) * d->size) - 0.0001;
	v->rx = (pl->yp - v->ry) * (-1 / tan(ra)) + pl->xp;
	v->yo = -d->size;
	v->xo = -v->yo * (-1 / tan(ra));
}

void	ft_check_horizontal_down(t_data *d, t_player *pl, t_check *v, float ra)
{
	v->ry = (((int)pl->yp / d->size) * d->size) + d->size;
	v->rx = (pl->yp - v->ry) * (-1 / tan(ra)) + pl->xp;
	v->yo = d->size;
	v->xo = -v->yo * (-1 / tan(ra));
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

float	ft_check_horizontal(t_data *d, t_player *pl, float ra, t_check *v)
{
	int		mx;
	int		my;
	int		dof;
	//t_check	v;

	dof = 0;
	if (ra < PI)//looking up
		ft_check_horizontal_up(d, pl, v, ra);
	if (ra > PI)//looking down
		ft_check_horizontal_down(d, pl, v, ra);
	if (!ra || ra == PI)
		ft_check_horizontal_l_r(d, pl, v, &dof);
	while (dof < d->h)
	{
		mx = (int)v->rx / d->size;		//pos x de la map
		my = (int)v->ry / d->size;		//pos y de la map
		if ((my >= 0 && mx >= 0 && my < d->h && mx < d->l) && d->map.m[my][mx] == '1')	//wall hit
		{
			for (int test = 0; test< d->size; test++)
				for (int test2 = 0; test2 < d->size; test2++)
					mlx_pixel_put(d->mlx, d->win, mx * d->size + test, my * d->size + test2, 0x5B034F);
			return (ft_dist(pl->xp, pl->yp, v->rx, v->ry));
		}
		else if (my < 0 ||my < 0 || my > d->h || mx > d->l)
			dof = d->h;
		else		//next line
			ft_check_horizontal_next(v, &dof);
	}
	return (-1);
}
