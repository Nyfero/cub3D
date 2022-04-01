/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:59:44 by jgourlin          #+#    #+#             */
/*   Updated: 2022/04/01 15:21:34 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_before_exec_bonus(t_data *data)
{
	destroy_sprite(data);
	if (data->map)
		ft_free_ls(data->map);
	if (data->pl)
		free(data->pl);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int	end_cub3d_bonus(t_data *data)
{
	destroy_sprite(data);
	mlx_clear_window(data->mlx, data->win3d);
	mlx_destroy_window(data->mlx, data->win3d);
	ft_free_ls(data->map);
	free(data->pl);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	destroy_rec(t_data *data, t_wall *w, t_wall *deb, int i)
{
	if (!w || (w == deb && i))
		return (0);
	if (w->no.img)
		mlx_destroy_image(data->mlx, w->no.img);
	if (w->so.img)
		mlx_destroy_image(data->mlx, w->so.img);
	if (w->we.img)
		mlx_destroy_image(data->mlx, w->we.img);
	if (w->ea.img)
		mlx_destroy_image(data->mlx, w->ea.img);
	destroy_rec(data, w->next, deb, 1);
	if (w)
		free(w);
	return (0);
}

void	destroy_sprite(t_data *data)
{
	destroy_rec(data, data->wall, data->wall, 0);
	if (data->screen.img)
		mlx_destroy_image(data->mlx, data->screen.img);
	if (data->mmap.gr)
		mlx_destroy_image(data->mlx, data->mmap.gr);
	if (data->mmap.wl)
		mlx_destroy_image(data->mlx, data->mmap.wl);
	if (data->mmap.pl)
		mlx_destroy_image(data->mlx, data->mmap.pl);
	if (data->mmap.odoor)
		mlx_destroy_image(data->mlx, data->mmap.odoor);
	if (data->mmap.cdoor)
		mlx_destroy_image(data->mlx, data->mmap.cdoor);
}
