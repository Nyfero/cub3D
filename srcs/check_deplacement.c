#include "cub3D.h"

int	ft_check_wall(float x, float y, t_data *d)
{
	int	pos_x;
	int	pos_y;

	pos_x = (int)x / d->size;
	pos_y = (int)y / d->size;
	if (d->map.m[pos_x][pos_y] == '1')
		return (1);
	return (0);
}

int	ft_check_radius(float x, float y, float r, t_data *d)
{
	int		i;
	int		j;
	float	tmp;

	i = (r * -1) + x + 1;
	j = (r * -1) + y + 1;
	while (i < r + x)
	{
		while (j < r + y)
		{
			tmp = sqrt(powf(x - i, 2) + powf(y - j, 2));
			if (tmp <= r)
				if (ft_check_wall(j, i, d))
					return (1);
			j++;
		}
		j = (r * -1) + y + 1;
		i++;
	}
	return (0);
}

int	ft_check_deplacement(t_data *d, t_player *p, float dx, float dy)
{
	float	tx;
	float	ty;

	tx = p->xp - dx;
	ty = p->yp - dy;
	ft_check_door(tx, ty, d);
	return (ft_check_radius(tx, ty, 5, d));
}

int	ft_check_deplacement_2(t_data *d, t_player *p)
{
	float	tx;
	float	ty;

	tx = p->xp + p->dxp;
	ty = p->yp + p->dyp;
	ft_check_door(tx, ty, d);
	return (ft_check_radius(tx, ty, 5, d));
}
