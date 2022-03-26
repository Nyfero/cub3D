#include "cub3D.h"

void	ft_3d_render(t_data *d)
{
	(void)d;
	float	disth;
	float	distv;
	int	r;
	
	distv = -1;
	r = 0;
	while (r < 1)
	{
		disth = ft_check_horizontal(d, d->pl);
		distv = ft_check_vertical(d, d->pl);
		printf("distv=%.3f || disth=%.3f\n", distv, disth);
		if (disth < 0)
		{
			printf("dist final = %f\n", distv);
		}
		else if (distv < 0)
		{
			printf("dist final = %f\n", disth);
		}
		else if (distv > disth)
			printf("dist final = %f\n", disth);
		else
			printf("dist final = %f\n", distv);
		r++;
	}
}