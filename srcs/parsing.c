#include "cub3D.h"

int	parsing(t_data *data, char *file)
{
	init_wall(data);
	if (parse_wall(data, file))
		return (1);
	if (open_map(data, file))
		return (1);
	return (0);
}

void	init_wall(t_data *data)
{
	data->wall.no = NULL;
	data->wall.so = NULL;
	data->wall.we = NULL;
	data->wall.ea = NULL;
	data->wall.size = 64;
	data->wall.fl = 0;
	data->wall.cl = 0;
	data->wall.next = NULL;
}

int	open_map(t_data *data, char *file)
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
		if (get_map(data, line))
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

int	get_map(t_data *data, char *line)
{
	int	i;

}
