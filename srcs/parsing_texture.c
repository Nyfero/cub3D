#include "cub3D.h"

int	parse_wall(t_data *data, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (parse_texture(data, line))
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
	}
	close(fd);
	return (0);
}

int	parse_texture(t_data *data, char *line)
{
	char	**tab;

	tab = NULL;
	if (line)
		tab = ft_split(line, ' ');
	if (!tab)
	{
		ft_putendl_fd("Malloc failed", 2);
		return (1);
	}
	if (!tab[0] || ft_isdigit(tab[0][0]))
	{
		ft_free_ls(tab);
		return (0);
	}
	if (get_texture(data, tab))
	{
		ft_free_ls(tab);
		return (1);
	}
	ft_free_ls(tab);
	return (0);
}

int	get_texture(t_data *data, char **tab)
{
	printf("tab[0]:%s\ntab[1]:%s\n", tab[0], tab[1]);
	if (!ft_strncmp(tab[0], "NO", ft_strlen(tab[0])) && !data->wall.no.i)
	{
		printf("01\n");
		data->wall.no.i = mlx_xpm_file_to_image(data->mlx, tab[1],
				&data->wall.no.w, &data->wall.no.h);
	}
	else if (!ft_strncmp(tab[0], "SO", ft_strlen(tab[0])) && !data->wall.so.i)
	{
		printf("02\n");
		data->wall.so.i = mlx_xpm_file_to_image(data->mlx, tab[1],
				&data->wall.so.w, &data->wall.so.h);
	}
	else if (!ft_strncmp(tab[0], "WE", ft_strlen(tab[0])) && !data->wall.we.i)
	{
		printf("03\n");
		data->wall.we.i = mlx_xpm_file_to_image(data->mlx, tab[1],
				&data->wall.we.w, &data->wall.we.h);
	}
	else if (!ft_strncmp(tab[0], "EA", ft_strlen(tab[0])) && !data->wall.ea.i)
	{
		printf("04\n");
		data->wall.ea.i = mlx_xpm_file_to_image(data->mlx, tab[1],
			&data->wall.ea.w, &data->wall.ea.h);
	}
	else if (!ft_strncmp(tab[0], "C", ft_strlen(tab[0])) && !data->wall.cl)
		data->wall.cl = get_color(tab[1]);
	else if (!ft_strncmp(tab[0], "F", ft_strlen(tab[0])) && !data->wall.fl)
		data->wall.fl = get_color(tab[1]);
	else
		return (error_file(5));
	return (0);
	
}

int	get_color(char *line)
{
	(void)line;
	return (1);
}
