/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:45:36 by jgourlin          #+#    #+#             */
/*   Updated: 2022/03/31 14:27:23 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_imge *print, int x, int y, int color)
{
	int	*dst;

	dst = print->addr + (y * 720 + x);
	*(int *)dst = color;
}

void	ft_3d_draw(t_data *d, float dist, t_3d_dist s, int *img)
{
	t_3d_draw	g;

	ft_3d_draw_init(d, &g, dist);
	while (g.y < d->size_screen)
	{
		if (g.y < g.line_o)
			my_mlx_pixel_put(&d->screen, s.r, g.y, d->wall->cl);
		else if (g.y > g.line_o && g.y <= g.line_o + g.line_h)
		{	
			my_mlx_pixel_put(&d->screen, s.r, g.y,
				(int) img[(int)g.ty * d->size + (int) s.tx]);
			g.ty += g.ty_step;
		}
		else
			my_mlx_pixel_put(&d->screen, s.r, g.y, d->wall->fl);
		g.y++;
	}
}

void	ft_3d_dist(t_data *d, float ra, int r)
{
	t_3d_dist	g;
	float		disth;
	float		distv;

	g.r = r;
	g.ca = d->pl->ap - ra;
	if (g.ca < 0)
		g.ca += 2 * PI;
	if (g.ca > 2 * PI)
		g.ca -= 2 * PI;
	disth = ft_check_horizontal(d, d->pl, ra, &g.vh);
	distv = ft_check_vertical(d, d->pl, ra, &g.vv);
	g.ra = ra;
	if (disth < 0)
		ft_3d_dist_vertical(d, distv * cos(g.ca), g);
	else if (distv < 0)
		ft_3d_dist_horizontal(d, disth * cos(g.ca), g);
	else if (distv > disth)
		ft_3d_dist_horizontal(d, disth * cos(g.ca), g);
	else
		ft_3d_dist_vertical(d, distv * cos(g.ca), g);
}

void	ft_3d_render(t_data *d)
{
	float	ra;
	int		r;

	ra = d->pl->ap - DR * 30;
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	r = 0;
	while (r < 720)
	{
		ft_3d_dist(d, ra, r);
		ra = ra + DR / 12;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
		r++;
	}
	mlx_put_image_to_window(d->mlx, d->win3d, d->screen.img, -1, -1);
	ft_mini_map(d);
}
