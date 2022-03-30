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
	printf("Wall NO xpm:%p\n", data->wall.no.img);
	printf("Wall NO int:%p\n", data->wall.no.addr);
	printf("Wall SO xpm:%p\n", data->wall.so.img);
	printf("Wall SO int:%p\n", data->wall.so.addr);
	printf("Wall WE xpm:%p\n", data->wall.we.img);
	printf("Wall WE int:%p\n", data->wall.we.addr);
	printf("Wall EA xpm:%p\n", data->wall.ea.img);
	printf("Wall EA int:%p\n\n", data->wall.ea.addr);
	printf("Floor:%d\n", data->wall.fl);
	printf("Celling:%d\n", data->wall.cl);
	printf("\t---END INFO TEXTURE---\n");
}
