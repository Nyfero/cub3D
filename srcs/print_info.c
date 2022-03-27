#include "cub3D.h"

void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	printf("\n\t---INFO MAP---\n");
	printf("\tMAP LENGHT:%d\n\tMAP HEIGHT:%d\n\n", data->map.x, data->map.y);
	while (data->map.m[++i])
	{
		j = -1;
		printf("(%02d)--", i);
		while (data->map.m[i][++j])
			printf("[%c]", data->map.m[i][j]);
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
	printf("Wall NO:%p\n", data->wall.no.img);
	printf("Wall SO:%p\n", data->wall.so.img);
	printf("Wall WE:%p\n", data->wall.we.img);
	printf("Wall EA:%p\n\n", data->wall.ea.img);
	printf("Floor:%d\n", data->wall.fl);
	printf("Celling:%d\n", data->wall.cl);
	printf("\t---END INFO TEXTURE---\n");
}
