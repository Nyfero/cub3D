/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:45:26 by jgourlin          #+#    #+#             */
/*   Updated: 2022/04/01 16:11:42 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_rotation(int nb, t_player *p)
{
	if (nb == 1)
	{
		p->ap -= 0.1;
		if (p->ap < 0)
			p->ap += 2 * PI;
	}
	else
	{
		p->ap += 0.1;
		if (p->ap > 2 * PI)
			p->ap -= 2 * PI;
	}
	p->dxp = (cos(p->ap) * MV);
	p->dyp = (sin(p->ap) * MV);
}

void	ft_deplacement_hor(t_data *d, int nb, t_player *p)
{
	float	temp_a;
	float	temp_x;
	float	temp_y;

	if (nb > 0)
	{
		temp_a = p->ap + PI / 2;
		if (temp_a > 2 * PI)
			temp_a -= 2 * PI;
		temp_x = cos(temp_a) * MV;
		temp_y = sin(temp_a) * MV;
		if (!ft_check_deplacement(d, p, temp_x, temp_y))
			ft_utils_game_change(d, temp_x, temp_y);
	}
	else
	{
		temp_a = p->ap - PI / 2;
		if (temp_a < 0)
			temp_a += 2 * PI;
		temp_x = cos(temp_a) * MV;
		temp_y = sin(temp_a) * MV;
		if (!ft_check_deplacement(d, p, temp_x, temp_y))
			ft_utils_game_change(d, temp_x, temp_y);
	}
}

void	ft_deplacement_vert(t_data *d, int nb, t_player *p)
{
	if (nb > 0)
	{
		if (!ft_check_deplacement_2(d, p))
		{
			p->xp += p->dxp;
			p->yp += p->dyp;
		}
	}
	else
	{
		if (!ft_check_deplacement(d, p, p->dxp, p->dyp))
		{
			p->xp -= p->dxp;
			p->yp -= p->dyp;
		}
	}
}

int	ft_game_event(int key, t_data *d)
{
	if (key == 65307)
		end_cub3d(d);
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
		ft_3d_render(d);
	return (0);
}

int	ft_game(t_data d)
{
	ft_3d_render(&d);
	mlx_hook(d.win3d, 02, (1L << 0), ft_game_event, &d);
	mlx_hook(d.win3d, 33, 1L << 5, end_cub3d, &d);
	mlx_loop(d.mlx);
	return (0);
}
