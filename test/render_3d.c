#include "cub3D.h"

void	ft_3d_draw(t_data *d, float dist, int r, unsigned int *img, int color)
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
//	printf("%d * %d / %.3f = %.3f lineo=%.3f\n", d->hwin, d->size, dist, line_h, line_o);
//	float	ty = 0;
//	float	ty_step = d->size / (float)line_h;

	//	printf("%d * %d / %.3f = %.3f lineo=%.3f\n", d->hwin, d->size, dist, line_h, line_o);


	(void)img;
	(void) color;
	// while (i >= 0)
	// {
	// 	printf("i=%d =", i);
	// 	printf("%d\n", img[i]);
	// 	i++;
	// }
	while (i < d->hwin)
	{
		//float c = img[((int)ty) * 64]; //trouver position pixel
		while (k < 12)
		{
	//		printf("ty=%.3f |tystep=%.3f | ty*64=%d\n", ty, ty_step, (int)ty*64);
			if (i < line_o)//non wall*/
				mlx_pixel_put(d->mlx, d->win3d, r * 12 + k, i, 0x48FF50);//vert plafond
		//	else if (i > line_o && i < line_o + line_h)
		//		mlx_pixel_put(d->mlx, d->win3d, r * 12 + k, i, color);//rose wall
			else if (i > line_o && i < line_o + line_h)
			{				
				mlx_pixel_put(d->mlx, d->win3d, r * 12 + k, i, (int)img[i * 64 + r * 4]);//rose wall
			}
			else
				mlx_pixel_put(d->mlx, d->win3d, r * 12 + k, i, 0xFF0000);//rouge sol
			k++;
		}
	//	ty += ty_step;
		k = 0;
		i++;
	}
}

unsigned int	*ft_test_img(t_data *d)
{
	char	*addr = 0;
	int		pixe = 5;
	int		sline = 5;
	int		endian = 50;
	//int		pos;
	
	printf("t_int = %lu\n", sizeof(int));
	printf("addre=%p | pixe=%d | sline=%d | endian=%d\n", addr, pixe, sline, endian);
	addr = mlx_get_data_addr(d->wall.no, &pixe, &sline, &endian);
	printf("addre=%p | pixe=%d | sline=%d | endian=%d\n", addr, pixe, sline, endian);
	
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
		disth = ft_check_horizontal(d, d->pl, ra);
		distv = ft_check_vertical(d, d->pl, ra);
	//	printf("distv=%.3f || disth=%.3f\n", distv, disth);
		if (disth < 0)
		{
			ft_3d_draw(d, distv * cos(ca), r, color, 0xFF48EE);//0xFF48EE
		//	printf("dist final = %f\n",distv);
		}
		else if (distv < 0)
		{
			ft_3d_draw(d, disth * cos(ca), r, color, 0xE341D4);//0xE341D4
		//	printf("dist final = %f\n",disth);
		}
		else if (distv > disth)
		{
			ft_3d_draw(d, disth * cos(ca), r, color, 0xE341D4);//0xE341D4
		//	printf("dist final = %f\n",disth);
		}
		else
		{
			ft_3d_draw(d, distv * cos(ca), r, color, 0xFF48EE);//0xFF48EE
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