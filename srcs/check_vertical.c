/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:45:19 by jgourlin          #+#    #+#             */
/*   Updated: 2022/03/31 14:27:45 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	dof = 0;
	if (ra < P2 || ra > P3)
		ft_check_vertical_left(d, pl, v, ra);
	if (ra > P2 && ra < P3)
		ft_check_vertical_right(d, pl, v, ra);
	if (!ra || ra == PI)
		ft_check_vertical_up_down(d, pl, v, &dof);
	while (dof < d->l)
	{
		mx = (int)v->rx / d->size;
		my = (int)v->ry / d->size;
		if ((my >= 0 && mx >= 0 && my < d->h && mx < d->l)
			&& (d->map[my][mx] == '1' || d->map[my][mx] == '2'))
			return (ft_dist(pl->xp, pl->yp, v->rx, v->ry));
		else if (my < 0 || my < 0 || my > d->h || mx > d->l)
			dof = d->l;
		else
			ft_check_vertical_next(v, &dof);
	}
	return (-1);
}
