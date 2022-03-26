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
			break;
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
	if (!ft_strncmp(tab[0], "NO", ft_strlen(tab[0])) && !data->wall.no)
		data->wall.no = mlx_xpm_file_to_image(data->mlx,
			tab[1], &data->wall.size, &data->wall.size);
	else if (!ft_strncmp(tab[0], "SO", ft_strlen(tab[0])) && !data->wall.so)
		data->wall.so = mlx_xpm_file_to_image(data->mlx,
			tab[1], &data->wall.size, &data->wall.size);
	else if (!ft_strncmp(tab[0], "WE", ft_strlen(tab[0])) && !data->wall.we)
		data->wall.we = mlx_xpm_file_to_image(data->mlx,
			tab[1], &data->wall.size, &data->wall.size);
	else if (!ft_strncmp(tab[0], "EA", ft_strlen(tab[0])) && !data->wall.ea)
		data->wall.ea = mlx_xpm_file_to_image(data->mlx,
			tab[1], &data->wall.size, &data->wall.size);
	else if (!ft_strncmp(tab[0], "C", ft_strlen(tab[0])) && !data->wall.cl)
		data->wall.cl = get_color(tab[1]);
	else if (!ft_strncmp(tab[0], "F", ft_strlen(tab[0])) && !data->wall.fl)
		data->wall.fl = get_color(tab[1]);
	else
		return (error_file(5));
	if (!data->wall.no || !data->wall.so || !data->wall.we || !data->wall.ea)
	{
		free_img(data);
		return (error_file(6));
	}
	return (0);
}

int	get_color(char *line)
{
	(void)line;
	return (1);
}
