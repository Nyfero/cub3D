/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:02:56 by gsap              #+#    #+#             */
/*   Updated: 2022/04/01 14:29:59 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv))
		return (1);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (2);
	if (parsing_bonus(&data, argv[1]))
	{
		exit_before_exec(&data);
		return (3);
	}
	data.win3d = mlx_new_window(data.mlx, 720, 720, "cub3d");
	ft_game(data);
	end_cub3d(&data);
	return (0);
}

int	sprite(t_data *d)
{
	t_wall	*ptr;

	ptr = d->wall;
	d->wall->next = (t_wall *)ft_calloc(sizeof(t_wall), 1);
	if (!d->wall->next)
		return (1);
	first_sprite(d);
	d->wall->next = (t_wall *)ft_calloc(sizeof(t_wall), 1);
	if (!d->wall->next)
		return (1);
	d->wall = d->wall->next;
	second_sprite(d);
	d->wall->next = ptr;
	return (0);
}

void	first_sprite(t_data *d)
{
	d->wall = d->wall->next;
	d->wall->no.img = mlx_xpm_file_to_image(d->mlx, "./d_img/north_1.xpm",
			&d->size, &d->size);
	d->wall->so.img = mlx_xpm_file_to_image(d->mlx, "./d_img/south_1.xpm",
			&d->size, &d->size);
	d->wall->we.img = mlx_xpm_file_to_image(d->mlx, "./d_img/weast_1.xpm",
			&d->size, &d->size);
	d->wall->ea.img = mlx_xpm_file_to_image(d->mlx, "./d_img/east_1.xpm",
			&d->size, &d->size);
	convert_img_to_int(d);
}

void	second_sprite(t_data *d)
{
	d->wall->no.img = mlx_xpm_file_to_image(d->mlx, "./d_img/north_2.xpm",
			&d->size, &d->size);
	d->wall->so.img = mlx_xpm_file_to_image(d->mlx, "./d_img/south_2.xpm",
			&d->size, &d->size);
	d->wall->we.img = mlx_xpm_file_to_image(d->mlx, "./d_img/weast_2.xpm",
			&d->size, &d->size);
	d->wall->ea.img = mlx_xpm_file_to_image(d->mlx, "./d_img/east_2.xpm",
			&d->size, &d->size);
	convert_img_to_int(d);
}
/*
void	destroy_sprite(t_data *data)
{
	t_wall	*ptr;
	t_wall	*aux;
	
	ptr = data->wall;
	while (ptr)
	{
		aux = ptr;
		if (ptr->next)
			ptr = ptr->next;
		if (aux->no.img)
			mlx_destroy_image(data->mlx, aux->no.img);
		if (aux->so.img)
			mlx_destroy_image(data->mlx, aux->so.img);
		if (aux->we.img)
			mlx_destroy_image(data->mlx, aux->we.img);
		if (aux->ea.img)
			mlx_destroy_image(data->mlx, aux->ea.img);
		aux->next = NULL;
		free(aux);
		aux = NULL;
	}
	if (data->screen.img)
		mlx_destroy_image(data->mlx, data->screen.img);
	if (data->mmap.gr)
		mlx_destroy_image(data->mlx, data->mmap.gr);
	if (data->mmap.wl)
		mlx_destroy_image(data->mlx, data->mmap.wl);
	if (data->mmap.pl)
		mlx_destroy_image(data->mlx, data->mmap.pl);
}
*/

int		destroy_rec_lol(t_data *data, t_wall *w)
{
	t_wall	*tmp;

	printf("ptr=%p\n", w);
	if (!w)
		return(0);
	if (w->no.img)
		mlx_destroy_image(data->mlx, w->no.img);
	if (w->so.img)
		mlx_destroy_image(data->mlx, w->so.img);
	if (w->we.img)
		mlx_destroy_image(data->mlx, w->we.img);
	if (w->ea.img)
		mlx_destroy_image(data->mlx, w->ea.img);
	tmp = w->next;
	w = NULL;
	free(w);
	destroy_rec_lol(data, tmp);
	return (0);
}

void	destroy_sprite(t_data *data)
{
	printf("debt\n");
	printf("debt\n");
	printf("debt\n");
	destroy_rec_lol(data, data->wall);
	printf("end\n");
	if (data->screen.img)
		mlx_destroy_image(data->mlx, data->screen.img);
	if (data->mmap.gr)
		mlx_destroy_image(data->mlx, data->mmap.gr);
	if (data->mmap.wl)
		mlx_destroy_image(data->mlx, data->mmap.wl);
	if (data->mmap.pl)
		mlx_destroy_image(data->mlx, data->mmap.pl);
}
