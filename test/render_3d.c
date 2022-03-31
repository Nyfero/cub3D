#include "cub3D.h"

void	my_mlx_pixel_put(t_imge *print, int x, int y, int color)
{
	int	*dst;

	dst = print->addr + (y * 720 + x);
	*(int*)dst = color;
}

void	ft_3d_draw(t_data *d, float dist, int r, int *img, float tx)
{
	float	line_h;
	float	line_o;
	int		y;

	float	ty;
	float ty_off;
	float ty_step;

	line_h = (d->hwin * d->size) / dist;
	ty_step = d->size / line_h;
	ty_off = 0;
	if (line_h > d->hwin)
	{
		ty_off = (line_h - d->hwin) / 2;
		line_h = d->hwin;
	}
	line_o = d->hwin / 2 - line_h / 2;	
	ty = ty_off * ty_step;
	y = 0;
	while (y < d->hwin)
	{
		if (y < line_o)
			my_mlx_pixel_put(&d->big_img, r, y, 0x48FF50);
		else if (y > line_o && y <= line_o + line_h)
		{	
			my_mlx_pixel_put(&d->big_img, r, y, (int) img[(int)ty * d->size + (int) tx]);
			ty += ty_step;
		}
		else
			my_mlx_pixel_put(&d->big_img, r, y, 0xFF0000);
		y++;
	}
}

void	ft_3d_dist(t_data *d, int r, float ra)
{
	float	disth;
	float	distv;
	t_check vh;
	t_check vv;
	float	ca;
	float	tx;

	ca = d->pl->ap - ra;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	disth = ft_check_horizontal(d, d->pl, ra, &vh);
	distv = ft_check_vertical(d, d->pl, ra, &vv);

	if (disth < 0)
	{
		tx = (int) (vv.ry) % d->size;
		if (ra < P2 || ra > P3)
			ft_3d_draw(d, distv * cos(ca), r, d->wall->ea.addr, d->size - 1 - tx);//0xFF48EE
		else
			ft_3d_draw(d, distv * cos(ca), r, d->wall->we.addr, tx);
	}
	else if (distv < 0)
	{
		tx = (int) (vh.rx) % d->size;
		if (ra > PI)
			ft_3d_draw(d, disth * cos(ca), r, d->wall->so.addr, d->size - 1 - tx);
		else
			ft_3d_draw(d, disth * cos(ca), r, d->wall->no.addr, tx);//0xE341D4
	}
	else if (distv > disth)
	{
		tx = (int) (vh.rx) % d->size;
		if (ra > PI)
			ft_3d_draw(d, disth * cos(ca), r, d->wall->so.addr, d->size - 1 - tx);
		else
			ft_3d_draw(d, disth * cos(ca), r, d->wall->no.addr, tx);//0xE341D4
	}
	else
	{
		tx = (int) (vv.ry) % d->size;
		if (ra < P2 || ra > P3)
			ft_3d_draw(d, distv * cos(ca), r, d->wall->ea.addr, d->size - 1 - tx);//0xFF48EE
		else
			ft_3d_draw(d, distv * cos(ca), r, d->wall->we.addr, tx);
	}
}

void	ft_3d_render(t_data *d)
{
	float	ra;
	int	r;

	ra = d->pl->ap - DR * 30;
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	r = 0;
	while (r < 720)
	{
		ft_3d_dist(d, r, ra);
		ra = ra + DR / 12;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;

		r++;
	}

	mlx_put_image_to_window(d->mlx, d->win3d, d->big_img.img ,-1, -1);
	printf("-----fin r----\n");
	ft_mini_map(d);
}