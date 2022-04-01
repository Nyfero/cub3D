/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:01:12 by gsap              #+#    #+#             */
/*   Updated: 2022/04/01 13:27:39 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_before_exec(t_data *data)
{
	free_img(data);
	if (data->wall)
		free(data->wall);
	if (data->map)
		ft_free_ls(data->map);
	if (data->pl)
		free(data->pl);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	free_img(t_data *data)
{
	if (data->wall->no.img)
		mlx_destroy_image(data->mlx, data->wall->no.img);
	if (data->wall->so.img)
		mlx_destroy_image(data->mlx, data->wall->so.img);
	if (data->wall->we.img)
		mlx_destroy_image(data->mlx, data->wall->we.img);
	if (data->wall->ea.img)
		mlx_destroy_image(data->mlx, data->wall->ea.img);
	if (data->screen.img)
		mlx_destroy_image(data->mlx, data->screen.img);
	if (data->mmap.gr)
		mlx_destroy_image(data->mlx, data->mmap.gr);
	if (data->mmap.wl)
		mlx_destroy_image(data->mlx, data->mmap.wl);
	if (data->mmap.pl)
		mlx_destroy_image(data->mlx, data->mmap.pl);
}

int	end_cub3d(t_data *data)
{
	free_img(data);
	if (data->wall)
		free(data->wall);
	mlx_clear_window(data->mlx, data->win3d);
	mlx_destroy_window(data->mlx, data->win3d);
	ft_free_ls(data->map);
	free(data->pl);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	exit_before_exec_bonus(t_data *data)
{
	//destroy_sprite(data);
	/*free_img(data);
	if (data->wall)
		free(data->wall);*/
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
	//free_img(data);
	if (data->wall)
		free(data->wall);
	mlx_clear_window(data->mlx, data->win3d);
	mlx_destroy_window(data->mlx, data->win3d);
	ft_free_ls(data->map);
	free(data->pl);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
