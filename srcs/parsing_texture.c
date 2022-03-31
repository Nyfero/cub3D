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
	int		ret;

	tab = NULL;
	ret = 0;
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
	if (!tab[1])
		ret = error_file(5);
	if (ret == 0 && get_texture(data, tab))
		ret = 1;
	ft_free_ls(tab);
	return (ret);
}

int	get_texture(t_data *data, char **tab)
{
	if (!ft_strncmp(tab[0], "NO", ft_strlen(tab[0])) && !data->wall->no.img)
		data->wall->no.img = mlx_xpm_file_to_image(data->mlx, tab[1],
				&data->size, &data->size);
	else if (!ft_strncmp(tab[0], "SO", ft_strlen(tab[0])) && !data->wall->so.img)
		data->wall->so.img = mlx_xpm_file_to_image(data->mlx, tab[1],
				&data->size, &data->size);
	else if (!ft_strncmp(tab[0], "WE", ft_strlen(tab[0])) && !data->wall->we.img)
		data->wall->we.img = mlx_xpm_file_to_image(data->mlx, tab[1],
				&data->size, &data->size);
	else if (!ft_strncmp(tab[0], "EA", ft_strlen(tab[0])) && !data->wall->ea.img)
		data->wall->ea.img = mlx_xpm_file_to_image(data->mlx, tab[1],
				&data->size, &data->size);
	else if (!ft_strncmp(tab[0], "C", ft_strlen(tab[0])) && data->wall->cl == -1)
		data->wall->cl = get_color(tab);
	else if (!ft_strncmp(tab[0], "F", ft_strlen(tab[0])) && data->wall->fl == -1)
		data->wall->fl = get_color(tab);
	else
		return (error_file(5));
	return (0);
}

int	get_color(char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (ft_lstrlen(line) == 2)
		return (one_line(line[1]));
	while (line[++i])
	{
		if (!tmp)
			tmp = ft_strdup(line[i]);
		else
			tmp = ft_strjoin_and_free_s1(tmp, line[i]);
	}
	i = one_line(tmp);
	free(tmp);
	return (i);
}

int	one_line(char *line)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	r = ft_atoi(line);
	i += len_nbr(r) + 1;
	if (!line[i])
		return (0 << 24 | r << 16 | 0 << 8 | 0);
	g = ft_atoi(&line[i]);
	i += len_nbr(g) + 1;
	if (!line[i])
		return (0 << 24 | r << 16 | g << 8 | 0);
	b = ft_atoi(&line[i]);
	i += len_nbr(b);
	while (line[i])
	{
		if (line[i++] != ' ')
		{
			error_file(5);
			return (-2);
		}
	}
	return (0 << 24 | r << 16 | g << 8 | b);
}
