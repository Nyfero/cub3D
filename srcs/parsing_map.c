/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:01:52 by gsap              #+#    #+#             */
/*   Updated: 2022/04/01 16:11:31 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parse_map(t_data *data, char *file)
{
	if (get_size_map(data, file))
		return (1);
	if (data->l <= 2 || data->h <= 2)
		return (error_file(7));
	if (data->l > 500 || data->h > 500)
		return (error_file(11));
	if (init_map(data))
		return (1);
	get_map(data, file);
	if (check_map_closed(data))
		return (1);
	if (init_player(data))
		return (1);
	if (get_player_info(data))
		return (1);
	return (0);
}

int	get_size_map(t_data *data, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] || data->h)
		{
			if (is_part_of_map(data, line))
				data->h++;
			else if (data->h)
			{
				free(line);
				close(fd);
				return (error_file(8));
			}
		}
		free(line);
	}
	close(fd);
	return (0);
}

int	is_part_of_map(t_data *data, char *line)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = 0;
	if (!line[0] || ft_isalpha(line[0]))
		return (0);
	while (line[++i])
	{
		if (line[i] == ' ' || line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'E' || line[i] == 'S' || line[i] == 'W')
			tmp++;
		else
			return (0);
	}
	if (tmp > data->l)
		data->l = tmp;
	return (1);
}

void	get_map(t_data *data, char *file)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(file, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_part_of_map(data, line))
		{
			j = -1;
			fill_map(data, line, i, j);
			i++;
		}
		free(line);
	}
	close(fd);
}

void	fill_map(t_data *data, char *line, int i, int j)
{
	while (line[++j])
	{
		if (line[j] == ' ')
			data->map[i][j] = '1';
		else
			data->map[i][j] = line[j];
	}
}
