#include "cub3D.h"

void	ft_check_vertical_right(t_data *d, t_player *pl, t_check *v, float ra)
{
	v->rx = (((int)pl->xp / d->size) * d->size) + d->size;
	v->ry = (pl->xp - v->rx) * -tan(ra) + pl->yp;
	v->xo = d->size;
	v->yo = -v->xo * -tan(ra);
}

void	ft_check_vertical_left(t_data *d, t_player *pl, t_check *v, float ra)
{
	v->rx = (((int)pl->xp / d->size) * d->size) - 0.0001;
	v->ry = (pl->xp - v->rx) * -tan(ra) + pl->yp;
	v->xo = -1 * d->size;
	v->yo = -v->xo * -tan(ra);
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


float	ft_check_vertical(t_data *d, t_player *pl, float ra, t_check *v)
{
	int		mx;
	int		my;
	int		dof;
//	t_check	v;

	dof = 0;
	if (ra < P2 || ra > P3)//looking left
		ft_check_vertical_left(d, pl, v, ra);
	if (ra > P2 && ra < P3)//looking right
		ft_check_vertical_right(d, pl, v, ra);
	if (!ra || ra == PI)//looking up / down
		ft_check_vertical_up_down(d, pl, v, &dof);
	while (dof < d->l)
	{
		mx = (int)v->rx / d->size;		//pos x de la map
		my = (int)v->ry / d->size;		//pos y de la map
		if ((my >= 0 && mx >= 0 && my < d->h && mx < d->l) && d->map.m[my][mx] == '1')	//wall hit
		{
			// printf("map[%d][%d] estun wall\n", mx, my);
			for (int test = 16; test< 32; test++)
			   	for (int test2 = 16; test2< 32; test2++)
			   		mlx_pixel_put(d->mlx, d->win, mx * d->size + test, my * d->size + test2, 0xFF0000);
			return (ft_dist(pl->xp, pl->yp, v->rx, v->ry));
		}
		else if (my < 0 || my < 0 || my > d->h || mx > d->l)
			dof = d->l;
		else	//next line
			ft_check_vertical_next(v, &dof);
	}
	return (-1);
}
