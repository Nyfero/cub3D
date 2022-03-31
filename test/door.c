/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:45:21 by jgourlin          #+#    #+#             */
/*   Updated: 2022/03/31 13:48:20 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_close_door(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < d->l)
	{
		while (y < d->h)
		{
			if (d->map.m[y][x] == '3')
				d->map.m[y][x] = '2';
			y++;
		}
		y = 0;
		x++;
	}
}

void	ft_check_door(float x, float y, t_data *d)
{
	int	i;
	int	j;
	int	x1;
	int	y1;

	i = -1;
	j = -1;
	ft_close_door(d);
	x1 = (int)x / 64;
	y1 = (int)y / 64;
	while (i < 2)
	{
		printf("%d-", x1 + i);
		while (j < 2)
		{
			printf("%d\n", y1 + j);
			if (d->map.m[x1 + i][y1 + j] == '2')
				printf("yo\n");
			j++;
		}
		j = -1;
		i++;
	}
printf("alpha 03\n");
}