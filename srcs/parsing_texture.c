/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:02:02 by gsap              #+#    #+#             */
/*   Updated: 2022/04/01 16:11:37 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	get_texture(t_data *d, char **tab)
{
	if (!ft_strncmp(tab[0], "NO", ft_strlen(tab[0])) && !d->wall->no.img)
		d->wall->no.img = mlx_xpm_file_to_image(d->mlx, tab[1],
				&d->size, &d->size);
	else if (!ft_strncmp(tab[0], "SO", ft_strlen(tab[0])) && !d->wall->so.img)
		d->wall->so.img = mlx_xpm_file_to_image(d->mlx, tab[1],
				&d->size, &d->size);
	else if (!ft_strncmp(tab[0], "WE", ft_strlen(tab[0])) && !d->wall->we.img)
		d->wall->we.img = mlx_xpm_file_to_image(d->mlx, tab[1],
				&d->size, &d->size);
	else if (!ft_strncmp(tab[0], "EA", ft_strlen(tab[0])) && !d->wall->ea.img)
		d->wall->ea.img = mlx_xpm_file_to_image(d->mlx, tab[1],
				&d->size, &d->size);
	else if (!ft_strncmp(tab[0], "C", ft_strlen(tab[0])) && d->cl == -1)
		d->cl = get_color(tab);
	else if (!ft_strncmp(tab[0], "F", ft_strlen(tab[0])) && d->fl == -1)
		d->fl = get_color(tab);
	else
		return (error_file(5));
	if (d->cl == -2 || d->fl == -2)
		return (1);
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
	r = get_red(line);
	while (ft_isdigit(line[++i]))
		;
	if (!line[i])
		return (0 << 24 | r << 16 | 0 << 8 | 0);
	g = get_green(&line[i]);
	while (ft_isdigit(line[++i]))
		;
	if (!line[i])
		return (0 << 24 | r << 16 | g << 8 | 0);
	b = get_blue(&line[i]);
	while (ft_isdigit(line[++i]))
		;
	if (check_no_more(line, i))
		return (-2);
	return (0 << 24 | r << 16 | g << 8 | b);
}
