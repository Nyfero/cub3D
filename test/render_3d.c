#include "cub3D.h"

void	ft_3d_draw(t_data *d, float dist, int r, unsigned int *img, int color, t_check *v, float ra)
{
	float	line_h;
	float	line_o;
	int		y;
	int		k;

	y = 0;
	k = 0;
	line_h = (d->hwin * d->size) / dist;

	float ty_step = d->size / line_h;
	float ty_off = 0;
	if (line_h > d->hwin)
	{
		ty_off = (line_h - d->hwin) / 2;
		line_h = d->hwin;
	}

	line_o = d->hwin / 2 - line_h / 2;	
//	printf("%d * %d / %.3f = %.3f lineo=%.3f\n", d->hwin, d->size, dist, line_h, line_o);
//	float	ty = 0;
//	float	ty_step = d->size / (float)line_h;

	//	printf("%d * %d / %.3f = %.3f lineo=%.3f\n", d->hwin, d->size, dist, line_h, line_o);

	float	ty = ty_off * ty_step;
	//printf("rx=%.3f\n", v->rx);
	float	tx = (int) (v->ry) / 1 % d->size;
	if (ra > PI)
	{
		//printf("r = %d || ra=%.3f\n", r , ra);
		tx = d->size - 1 - tx;
	}
	(void)img;
	(void) color;
	(void)ra;
	// while (i >= 0)
	// {
	// 	printf("i=%d =", i);
	// 	printf("%d\n", img[i]);
	// 	i++;
	
	//printf("salut\n");
	//printf("ty=%d |tystep=%.3f | ty*64=%d| line_h=%f\n", ty, ty_step, (int)ty*64, line_h);

	while (y < d->hwin)
	{

		//float c = img[((int)ty) * 64]; //trouver position pixel
		while (k < 12)
		{
			//printf("ty=%d |tystep=%.3f | ty*64=%d| line_h=%f\n", ty, ty_step, (int)ty*64, line_h);
			if (y < line_o)//non wall*/
				mlx_pixel_put(d->mlx, d->win3d, r * 12 + k, y, 0x48FF50);//vert plafond
		//	else if (i > line_o && i < line_o + line_h)
		//		mlx_pixel_put(d->mlx, d->win3d, r * 12 + k, i, color);//rose wall
			else if (y > line_o && y < line_o + line_h)
			{		
				//if (k == 0)printf("ty=%d |tystep=%.3f | ty*64=%d| line_h=%f\n", ty, ty_step, (int)ty*64, line_h);
				mlx_pixel_put(d->mlx, d->win3d, r * 12 + k, y, img[(int)ty * 64 + (int) tx]);//rose wall
				if (k == 0)
				{
				//	printf("pixel[%.3f] =%X\n", ty, img[(int)ty * 64]);
					ty += ty_step;
				}
			}
			else
				mlx_pixel_put(d->mlx, d->win3d, r * 12 + k, y, 0xFF0000);//rouge sol
			k++;
		}
	//	ty += ty_step;
		k = 0;
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
	addr = mlx_get_data_addr(d->wall.no, &pixe, &sline, &endian);
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
			mlx_pixel_put(d->mlx, d->win, x, y, addr_int[x + y * d->size]);
			y++;
		}
		y = 0;
		x++;
	}
	return (addr_int);
}

void	ft_3d_render(t_data *d)
{
	float	disth;
	float	distv;
	float	ra;
	float	ca;
	t_check	v1;
	t_check	v2;
	int	r;

	unsigned int	*color;

	color = ft_test_img(d);
	
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
		disth = ft_check_horizontal(d, d->pl, ra, &v1);
		distv = ft_check_vertical(d, d->pl, ra, &v2);
	//	printf("distv=%.3f || disth=%.3f\n", distv, disth);
		if (disth < 0)
		{
			ft_3d_draw(d, distv * cos(ca), r, color, 0xFF48EE, &v2, ra);//0xFF48EE
		//	printf("dist final = %f\n",distv);
		}
		else if (distv < 0)
		{
			ft_3d_draw(d, disth * cos(ca), r, color, 0xE341D4, &v1, ra);//0xE341D4
		//	printf("dist final = %f\n",disth);
		}
		else if (distv > disth)
		{
			ft_3d_draw(d, disth * cos(ca), r, color, 0xE341D4, &v1, ra);//0xE341D4
		//	printf("dist final = %f\n",disth);
		}
		else
		{
			ft_3d_draw(d, distv * cos(ca), r, color, 0xFF48EE, &v2, ra);//0xFF48EE
		//	printf("dist final = %f\n",distv);
		}
		ra = ra + DR;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;

		r++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->wall.no, 64, 64);
	mlx_put_image_to_window(d->mlx, d->win, d->wall.so, 200, 200);
	mlx_put_image_to_window(d->mlx, d->win, d->wall.ea, 300, 300);
	mlx_put_image_to_window(d->mlx, d->win, d->wall.we, 400, 400);

	//ft_test_img(d);
	printf("-----fin r----\n");
}