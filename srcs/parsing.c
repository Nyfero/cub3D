#include "cub3D.h"

int	parsing(t_data *data, char *file)
{
	init_wall(data);
	if (parse_wall(data, file))
		return (1);
	if (!data->wall.no.img || !data->wall.so.img || !data->wall.we.img
		|| !data->wall.ea.img || data->wall.fl < 0 || data->wall.cl < 0)
		return (error_file(6));
	convert_img_to_int(data);
	print_texture(data);
	if (parse_map(data, file))
		return (1);
	return (0);
}

void	init_wall(t_data *data)
{
	data->wall.no.img = NULL;
	data->wall.so.img = NULL;
	data->wall.we.img = NULL;
	data->wall.ea.img = NULL;
	data->wall.fl = -1;
	data->wall.cl = -1;
	data->size = 64;
	data->h = 0;
	data->l = 0;
}

int	init_map(t_data *data)
{
	int	i;

	data->map = (char **)malloc(sizeof(char *) * (data->h + 1));
	if (!data->map)
	{
		ft_putendl_fd("Malloc failed", 2);
		return (1);
	}
	i = 0;
	while (i < data->h)
	{
		data->map[i] = (char *)ft_calloc(sizeof(char), (data->l + 1));
		if (!data->map[i])
		{
			ft_putendl_fd("Malloc failed", 2);
			ft_free_ls(data->map);
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

void	convert_img_to_int(t_data *data)
{
	char	*tmp;
	
	tmp = mlx_get_data_addr(data->wall.no.img, &data->wall.no.pixel,
			&data->wall.no.line, &data->wall.no.endian);
	data->wall.no.addr = (unsigned int	*)tmp;
	tmp = mlx_get_data_addr(data->wall.so.img, &data->wall.so.pixel,
			&data->wall.so.line, &data->wall.so.endian);
	data->wall.so.addr = (unsigned int	*)tmp;
	tmp = mlx_get_data_addr(data->wall.we.img, &data->wall.we.pixel,
			&data->wall.we.line, &data->wall.we.endian);
	data->wall.we.addr = (unsigned int	*)tmp;
	tmp = mlx_get_data_addr(data->wall.ea.img, &data->wall.ea.pixel,
			&data->wall.ea.line, &data->wall.ea.endian);
	data->wall.ea.addr = (unsigned int	*)tmp;
}
