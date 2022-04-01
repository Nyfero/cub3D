/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:32:16 by gsap              #+#    #+#             */
/*   Updated: 2022/04/01 14:32:45 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_game_event_bonus(int key, t_data *d)
{
	if (key == 65307)
		end_cub3d_bonus(d);
	if (key == 65361)
		ft_rotation(1, d->pl);
	if (key == 65363)
		ft_rotation(-1, d->pl);
	if (key == 119)
		ft_deplacement_vert(d, -1, d->pl);
	if (key == 97)
		ft_deplacement_hor(d, -1, d->pl);
	if (key == 115)
		ft_deplacement_vert(d, 1, d->pl);
	if (key == 100)
		ft_deplacement_hor(d, 1, d->pl);
	if (key == 65307 || key == 65361 || key == 65363 || key == 119 || key == 97
		|| key == 115 || key == 100)
	{
		ft_3d_render(d);
		if (d->wall->next)
			d->wall = d->wall->next;
	}
	return (0);
}

int	ft_game_bonus(t_data d)
{
	ft_3d_render(&d);
	mlx_hook(d.win3d, 02, (1L << 0), ft_game_event, &d);
	mlx_hook(d.win3d, 33, 1L << 5, end_cub3d, &d);
	mlx_loop(d.mlx);
	return (0);
}
