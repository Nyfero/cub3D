#include "cub3D.h"

int	parse_map(t_data *data, char *file)
{
	get_size_map(data, file);
	if (data->map.x <= 2 || data->map.y <= 2)
		return (error_file(7));
	if (data->map.x > 500 || data->map.y > 500)
		return (error_file(11));
	if (init_map(data))
		return (1);
	get_map(data, file);
	print_map(data);
	if (check_map_closed(data))
		return (1);
	if (init_player(data))
		return (1);
	if (get_player_info(data))
		return (1);
	print_player(data);
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
		if (line[0] || data->map.y)
		{
			if (is_part_of_map(data, line))
				data->map.y++;
			else if (data->map.y)
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
	if (tmp > data->map.x)
		data->map.x = tmp;
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
			data->map.m[i][j] = '1';
		else
			data->map.m[i][j] = line[j];
	}
}
