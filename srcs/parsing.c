#include "cub3D.h"

int	parsing(t_data *data, char *file)
{
	init_wall(data);
	if (parse_wall(data, file))
		return (1);
	if (!data->wall.no || !data->wall.so || !data->wall.we || !data->wall.ea
		|| data->wall.fl == -1 || data->wall.cl == -1)
	{
		free_img(data);
		return (error_file(6));
	}
	print_texture(data);
	if (parse_map(data, file))
		return (1);
	return (0);
}

void	init_wall(t_data *data)
{
	data->wall.no = NULL;
	data->wall.so = NULL;
	data->wall.we = NULL;
	data->wall.ea = NULL;
	data->map.m = 0;
	data->wall.fl = 0;
	data->wall.cl = 0;
	data->wall.next = NULL;
	data->map.y = 0;
	data->map.x = 0;
	data->pl = NULL;
	data->size = 64;
}

int	init_map(t_data *data)
{
	int	i;

	data->map.m = (char **)malloc(sizeof(char *) * (data->map.y + 1));
	if (!data->map.m)
	{
		ft_putendl_fd("Malloc failed", 2);
		return (1);
	}
	i = 0;
	while (i < data->map.y)
	{
		data->map.m[i] = (char *)ft_calloc(sizeof(char), (data->map.x + 1));
		if (!data->map.m[i])
		{
			ft_putendl_fd("Malloc failed", 2);
			ft_free_ls(data->map.m);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_player(t_data *data)
{
	data->pl = ft_calloc(sizeof(t_player), 1);
	if (!data->pl)
	{
		ft_putendl_fd("Malloc failed", 2);
		return (1);
	}
	data->pl->xp = 0;
	data->pl->yp = 0;
	data->pl->dxp = 0;
	data->pl->dyp = 0;
	data->pl->ap = 0;
	return (0);
}

int	len_nbr(int nbr)
{
	int	compt;

	compt = 1;
	while (nbr / 10 > 0)
	{
		nbr = nbr / 10;
		compt++;
	}
	return (compt);
}
