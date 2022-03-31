/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:45:16 by jgourlin          #+#    #+#             */
/*   Updated: 2022/03/31 17:38:31 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	dof = 0;
	if (ra < PI)
		ft_check_horizontal_up(d, pl, v, ra);
	if (ra > PI)
		ft_check_horizontal_down(d, pl, v, ra);
	if (!ra || ra == PI)
		ft_check_horizontal_l_r(d, pl, v, &dof);
	while (dof < d->h)
	{
		mx = (int)v->rx / d->size;
		my = (int)v->ry / d->size;
		if ((my >= 0 && mx >= 0 && my < d->h && mx < d->l)
			&& (d->map[my][mx] == '1' || d->map[my][mx] == '2'))
			return (ft_dist(pl->xp, pl->yp, v->rx, v->ry));
		else if (my < 0 || my < 0 || my > d->h || mx > d->l)
			dof = d->h;
		else
			ft_check_horizontal_next(v, &dof);
	}
	return (-1);
}
