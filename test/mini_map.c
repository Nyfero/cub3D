/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:45:31 by jgourlin          #+#    #+#             */
/*   Updated: 2022/03/31 13:48:24 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	short_pitw(t_data *d, void *img, int x, int y)
{
	mlx_put_image_to_window(d->mlx, d->win3d, img, x, y);
}

void	ft_mini_map_if(t_data *d, int y, int x)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (i < 2)
	{
		while (j < 2)
		{
			if (d->map.m[y + j][x + i] == '0')
				short_pitw(d, d->s, (i + 1) * 64, (j + 1) * 64);
			if (d->map.m[y + j][x + i] == '1')
				short_pitw(d, d->w, (i + 1) * 64, (j + 1) * 64);
			if (d->map.m[y + j][x + i] == '2')
				short_pitw(d, d->cdoor, (i + 1) * 64, (j + 1) * 64);
			if (d->map.m[y + j][x + i] == '3')
				short_pitw(d, d->odoor, (i + 1) * 64, (j + 1) * 64);
			j++;
		}
		j = -1;
		i++;
	}
}

void	ft_mini_map(t_data *d)
{
	int	x;
	int	y;

	y = (int)d->pl->yp / 64;
	x = (int)d->pl->xp / 64;
	ft_mini_map_if(d, y, x);
	mlx_put_image_to_window(d->mlx, d->win3d, d->p,
		62 + (int)d->pl->xp % 64, 62 + (int)d->pl->yp % 64);
}
