#include "cub3D.h"

void	ft_3d_draw(t_data *d, float dist, int r, int color)
{
	float	line_h;
	float	line_o;
	int		i;
	int		k;

	i = 0;
	k = 0;
	line_h = (d->hwin * d->size) / dist;
	if (line_h > d->hwin)
		line_h = d->hwin;
	line_o = d->hwin / 2 - line_h / 2;	
	printf("%d * %d / %.3f = %.3f lineo=%.3f\n", d->hwin, d->size, dist, line_h, line_o);
	while (i < d->hwin)
	{
		while (k < 12)
		{
			if (i < line_o)//non wall*/
				mlx_pixel_put(d->mlx, d->win3d, r * 12 + k, i, 0x48FF50);//vert plafond
			else if (i > line_o && i < line_o + line_h)
				mlx_pixel_put(d->mlx, d->win3d, r * 12 + k, i, color);//rose wall
			else
				mlx_pixel_put(d->mlx, d->win3d, r * 12 + k, i, 0xFF0000);//rouge sol
			k++;
		}
		k = 0;
		i++;
	}
}

void	ft_3d_render(t_data *d)
{
	float	disth;
	float	distv;
	float	ra;
	float	ca;
	int	r;
	
	distv = -1;
	ra = d->pl->ap - DR * 30;
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	r = 0;
	while (r < 60)
	{
		ca = d->pl->ap - ra;
		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
//		printf("------ra = %.3f|| \n", ra);
		disth = ft_check_horizontal(d, d->pl, ra);
		distv = ft_check_vertical(d, d->pl, ra);
	//	printf("distv=%.3f || disth=%.3f\n", distv, disth);
		if (disth < 0)
		{
			ft_3d_draw(d, distv * cos(ca), r, 0xFF48EE);
			printf("dist final = %f\n",distv);
		}
		else if (distv < 0)
		{
			ft_3d_draw(d, disth * cos(ca), r, 0xE341D4);
			printf("dist final = %f\n",disth);
		}
		else if (distv > disth)
		{
			ft_3d_draw(d, disth * cos(ca), r, 0xE341D4);
			printf("dist final = %f\n",disth);
		}
		else
		{
			ft_3d_draw(d, distv * cos(ca), r, 0xFF48EE);
			printf("dist final = %f\n",distv);
		}
		ra = ra + DR;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;

		r++;
	}
	printf("-----fin r----\n");
}