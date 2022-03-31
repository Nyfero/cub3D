/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:45:34 by jgourlin          #+#    #+#             */
/*   Updated: 2022/03/31 13:48:25 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_3d_dist_horizontal(t_data *d, float dist, t_3d_dist g)
{
	g.tx = (int)(g.vh.rx) % d->size;
	if (g.ra > PI)
	{
		g.tx = d->size - 1 - g.tx;
		ft_3d_draw(d, dist, g, d->wall->so.addr);
	}
	else
		ft_3d_draw(d, dist, g, d->wall->no.addr);
}

void	ft_3d_dist_vertical(t_data *d, float dist, t_3d_dist g)
{
	g.tx = (int)(g.vv.ry) % d->size;
	if (g.ra < P2 || g.ra > P3)
	{
		g.tx = d->size - 1 - g.tx;
		ft_3d_draw(d, dist, g, d->wall->ea.addr);
	}
	else
		ft_3d_draw(d, dist, g, d->wall->we.addr);
}

void	ft_3d_draw_init(t_data *d, t_3d_draw *g, float dist)
{
	g->line_h = (d->hwin * d->size) / dist;
	g->ty_step = d->size / g->line_h;
	g->ty_off = 0;
	if (g->line_h > d->hwin)
	{
		g->ty_off = (g->line_h - d->hwin) / 2;
		g->line_h = d->hwin;
	}
	g->line_o = d->hwin / 2 - g->line_h / 2;
	g->ty = g->ty_off * g->ty_step;
	g->y = 0;
}
