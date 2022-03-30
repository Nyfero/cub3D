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
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j] == ' ' || data->map[i][j] == '1')
			j++;
		if (data->map[i][j] && data->map[i][j] == '0')
		{
			if (j == 0 || j == data->l - 1)
				return (error_file(9));
			if (i < data->h - 1)
				if (!data->map[i - 1][j] || !data->map[i + 1][j]
						|| !data->map[i][j + 1])
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
	while (data->map[++i])
	{
		j = 0;
		if (i < data->h - 1)
		{
			while (data->map[i][j])
				j++;
			j--;
			while (data->map[i][j] != '0' && j > 0)
				j--;
			if (data->map[i][j] == '0')
			{
				if (!data->map[i - 1][j] || !data->map[i + 1][j]
						|| j == data->l)
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
	while (data->map[0][++i])
		if (data->map[0][i] != '1' && data->map[0][i] != ' ')
			return (error_file(9));
	while (i < data->l)
	{
		if (data->map[1][i] && data->map[1][i] == '0')
			return (error_file(9));
		i++;
	}
	j = -1;
	i = data->h - 1;
	while (data->map[i][++j])
		if (data->map[i][j] != '1' && data->map[i][j] != ' ')
			return (error_file(9));
	while (j < data->l)
	{
		if (data->map[i - 1][j] && data->map[i - 1][j] == '0')
			return (error_file(9));
		j++;
	}
	return (0);
}

int	len_nbr(int nbr)
{
	int	compt;

	compt = 1;
	while (nbr / 10 > 0)
	{
		nbr = nbr / 10;
		compt++;
	}
	return (compt);
}
