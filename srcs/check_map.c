#include "cub3D.h"

int	check_map_closed(t_data *data)
{
	if (check_top_and_bot(data))
		return (1);
	if (check_left(data))
		return (1);
	if (check_right(data))
		return (1);
	return (0);
}

int	check_left(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.m[++i])
	{
		j = 0;
		while (data->map.m[i][j] == ' ' || data->map.m[i][j] == '1')
			j++;
		if (data->map.m[i][j] && data->map.m[i][j] == '0')
		{
			if (j == 0 || j == data->map.x - 1)
				return (error_file(9));
			if (i < data->map.y - 1)
				if (!data->map.m[i - 1][j] || !data->map.m[i + 1][j]
						|| !data->map.m[i][j + 1])
					return (error_file(9));
		}
	}
	return (0);
}

int	check_right(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.m[++i])
	{
		j = 0;
		if (i < data->map.y - 1)
		{
			while (data->map.m[i][j])
				j++;
			j--;
			while (data->map.m[i][j] != '0' && j > 0)
				j--;
			if (data->map.m[i][j] == '0')
			{
				if (!data->map.m[i - 1][j] || !data->map.m[i + 1][j]
						|| j == data->map.x)
					return (error_file(9));
			}
		}
	}
	return (0);
}

int	check_top_and_bot(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map.m[0][++i])
		if (data->map.m[0][i] != '1' && data->map.m[0][i] != ' ')
			return (error_file(9));
	while (i < data->map.x)
	{
		if (data->map.m[1][i] && data->map.m[1][i] == '0')
			return (error_file(9));
		i++;
	}
	j = -1;
	i = data->map.y - 1;
	while (data->map.m[i][++j])
		if (data->map.m[i][j] != '1' && data->map.m[i][j] != ' ')
			return (error_file(9));
	while (j < data->map.x)
	{
		if (data->map.m[i - 1][j] && data->map.m[i - 1][j] == '0')
			return (error_file(9));
		j++;
	}
	return (0);
}
