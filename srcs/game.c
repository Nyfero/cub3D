/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:45:26 by jgourlin          #+#    #+#             */
/*   Updated: 2022/03/31 15:29:30 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#include "cub3D.h"

void	ft_put_img(t_data *d, void *image, int x, int y)
{
	mlx_put_image_to_window(d->mlx, d->win, image, x, y);
}

void	ft_creation_img(t_data *d)
{
	int	i;
	int	jt;

	jt = 5;
	i = 32;
	printf("i = %d\n", i);
	d->s = mlx_xpm_file_to_image(d->mlx, "./d_img/floor.xpm", &i, &i);
	d->w = mlx_xpm_file_to_image(d->mlx, "./d_img/wall.xpm", &i, &i);
	d->p = mlx_xpm_file_to_image(d->mlx, "./d_img/player.xpm", &jt, &jt);
	d->cdoor = mlx_xpm_file_to_image(d->mlx, "./d_img/cdoor.xpm", &jt, &jt);
	d->odoor = mlx_xpm_file_to_image(d->mlx, "./d_img/odoor.xpm", &jt, &jt);
	if (d->s == 0 || d->w == 0 || d->p == 0)
		cub3d_exit(d);
}

void	ft_affichage_map(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < d->h)
	{
		while (d->map.m[i][j] != 0)
		{
			if (d->map.m[i][j] == '1')
				ft_put_img(d, d->w, j * 32, i * 32);
			if (d->map.m[i][j] == '0')
				ft_put_img(d, d->s, j * 32, i * 32);
			if (d->map.m[i][j] == '2')
			{
				printf("close cdoor\n");
				ft_put_img(d, d->cdoor, j * 32, i * 32);

			}
			if (d->map.m[i][j] == '3')
			{
				printf("close odoor\n");
				ft_put_img(d, d->odoor, j * 32, i * 32);
			}
			j++;
		}
		j = 0;
		i++;
	//	printf("line j = %d size = %d\n", j, d->size);
	}
	//ft_put_img(d, d->p, (d->pl->xp * 5) - 2, (d->pl->yp  * 5) - 2);
	ft_put_img(d, d->p, d->pl->xp * -2 - 2, d->pl->yp * -2 - 2);
	//printf("end\n");
}

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
	{
		ft_affichage_map(d);
		ft_3d_render(d);
		if (d->wall->next)
			d->wall = d->wall->next;
	}
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
