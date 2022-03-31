#include "cub3D.h"

int	parsing_bonus(t_data *data, char *file)
{
	init_wall(data);
	if (parse_wall(data, file))
		return (1);
	if (!data->wall.no.img || !data->wall.so.img || !data->wall.we.img
		|| !data->wall.ea.img || data->wall.fl < 0 || data->wall.cl < 0)
		return (error_file(6));
	convert_img_to_int(data);
	print_texture(data);
	if (parse_map_bonus(data, file))
		return (1);
	if (create_mini_map_bonus(data))
		return (1);
	return (0);
}

int	parse_map_bonus(t_data *data, char *file)
{
	if (get_size_map_bonus(data, file))
		return (1);
	if (data->l <= 2 || data->h <= 2)
		return (error_file(7));
	if (data->l > 500 || data->h > 500)
		return (error_file(11));
	if (init_map(data))
		return (1);
	get_map_bonus(data, file);
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

int	get_size_map_bonus(t_data *data, char *file)
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
			if (is_part_of_map_bonus(data, line))
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

int	is_part_of_map_bonus(t_data *data, char *line)
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
			|| line[i] == 'E' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == '2')
			tmp++;
		else
			return (0);
	}
	if (tmp > data->l)
		data->l = tmp;
	return (1);
}

void	get_map_bonus(t_data *data, char *file)
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
		if (is_part_of_map_bonus(data, line))
		{
			j = -1;
			fill_map(data, line, i, j);
			i++;
		}
		free(line);
	}
	close(fd);
}
