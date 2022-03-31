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
	/*
//	printf("%d * %d / %.3f = %.3f lineo=%.3f\n", d->hwin, d->size, dist, line_h, line_o);
//	float	ty = 0;
//	float	ty_step = d->size / (float)line_h;

	//	printf("%d * %d / %.3f = %.3f lineo=%.3f\n", d->hwin, d->size, dist, line_h, line_o);

	float	ty = ty_off * ty_step;
	//printf("rx=%.3f\n", v->rx);s
	float	tx = (int) (v->rx) / 1 % d->size;
	if (ra > PI)
	{
		//printf("r = %d || ra=%.3f\n", r , ra);
		//	printf//tx = d->size - 1 - tx;
	}
	(void)img;
	(void) color;
	(void)ra;
	(void)y;
	(void)k;
	(void)ty;
	(void)tx;
	// while (i >= 0)
	// {
	// 	printf("i=%d =", i);
	// 	printf("%d\n", img[i]);
	// 	i++;
	
	//printf("salut\n");
	//printf("ty=%d |tystep=%.3f | ty*64=%d| line_h=%f\n", ty, ty_step, (int)ty*64, line_h);
*/
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
	//	ty += ty_step;
	//k = 0;
	y++;
	}
}

unsigned int	*ft_test_img(t_data *d)
{
	char	*addr = 0;
	int		pixe = 5;
	int		sline = 5;
	int		endian = 50;
	//int		pos;
	
//	printf("t_int = %lu\n", sizeof(int));
//	printf("addre=%p | pixe=%d | sline=%d | endian=%d\n", addr, pixe, sline, endian);
	addr = mlx_get_data_addr(d->wall->no.img, &pixe, &sline, &endian);
	//printf("addre=%p | pixe=%d | sline=%d | endian=%d\n", addr, pixe, sline, endian);
	
	int y = 0; //y i
	int	x = 0; //x j
	unsigned int	*addr_int;
	addr_int = (unsigned int *)addr;
	//return (addr_int);
	while (x < d->size)
	{
		while(y < d->size)
		{
		//	pos = (y * sline + x * (pixe / 8));
			my_mlx_pixel_put(&d->big_img, x, y, 0xFF0000);
			y++;
		}
		y = 0;
		x++;
	}
	return (addr_int);
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

	/*mlx_put_image_to_window(d->mlx, d->win3d, d->big_img.img ,-1, -1);
	printf("-----fin r----\n");
	ft_mini_map(d);*/
}
