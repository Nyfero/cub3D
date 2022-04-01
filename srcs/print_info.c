/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:02:10 by gsap              #+#    #+#             */
/*   Updated: 2022/04/01 11:45:43 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	printf("\n\t---INFO MAP---\n");
	printf("\tMAP LENGHT:%d\n\tMAP HEIGHT:%d\n\n", data->l, data->h);
	while (data->map[++i])
	{
		j = -1;
		printf("(%02d)--", i);
		while (data->map[i][++j])
			printf("[%c]", data->map[i][j]);
		printf("\n");
	}
	printf("\t---END INFO MAP---\n");
}

void	print_player(t_data *data)
{
	printf("\n\t---INFO PLAYER---\n");
	printf("player pos X:%f\n", data->pl->xp);
	printf("player pos Y:%f\n", data->pl->yp);
	printf("player Dx:%f\n", data->pl->dxp);
	printf("player Dy:%f\n", data->pl->dyp);
	printf("player rotation:%f\n", data->pl->ap);
	printf("\t---END INFO PLAYER---\n");
}

void	print_texture(t_data *data)
{
	printf("\n\t---INFO TEXTURE---\n");
	printf("Wall NO xpm:%p\n", data->wall->no.img);
	printf("Wall NO int:%p\n", data->wall->no.addr);
	printf("Wall SO xpm:%p\n", data->wall->so.img);
	printf("Wall SO int:%p\n", data->wall->so.addr);
	printf("Wall WE xpm:%p\n", data->wall->we.img);
	printf("Wall WE int:%p\n", data->wall->we.addr);
	printf("Wall EA xpm:%p\n", data->wall->ea.img);
	printf("Wall EA int:%p\n\n", data->wall->ea.addr);
	printf("Floor:%d\n", data->fl);
	printf("Celling:%d\n", data->cl);
	printf("\t---END INFO TEXTURE---\n");
}

void	print_all(t_data *data)
{
	printf("\n\t---INFO ALL---\n");
	printf("Screen img:%p\n", data->screen.img);
	printf("data->size_screen :%d\n", data->size_screen);
	printf("data->mmap.gr:%p\n", data->mmap.gr);
	printf("ata->mmap.wl:%p\n", data->mmap.wl);
	printf("data->mmap.pl:%p\n", data->mmap.pl);
	printf("data->mmap.cdoor:%p\n", data->mmap.cdoor);
	printf("data->mmap.odoor:%p\n", data->mmap.odoor);
	printf("data->size:%d\n\n", data->size);
	printf("\t---END INFO ALL---\n");
}
