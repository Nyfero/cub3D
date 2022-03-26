#include "cub3D.h"

int	get_player_info(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map.m[++i])
	{
		j = -1;
		while (data->map.m[i][++j])
		{
			if (data->map.m[i][j] == 'N' || data->map.m[i][j] == 'S'
				|| data->map.m[i][j] == 'E' || data->map.m[i][j] == 'W')
				if (place_player(data, i, j))
					return (1);
		}
	}
	return (0);
}

int	place_player(t_data *data, int i, int j)
{
	if (data->map.m[i][j] == 'N' && !data->pl->xp)
		data->pl->ap = 3.1415926535 / 2;
	else if (data->map.m[i][j] == 'S' && !data->pl->xp)
		data->pl->ap = 3 * 3.1415926535 / 2;
	else if (data->map.m[i][j] == 'E' && !data->pl->xp)
		data->pl->ap = 0;
	else if (data->map.m[i][j] == 'W' && !data->pl->xp)
		data->pl->ap = 3.1415926535;
	else
		return (error_file(10));
	data->pl->xp = j * data->size;
	data->pl->yp = i * data->size;
	data->pl->dxp = (cos(data->pl->ap) * MV);
	data->pl->dyp = (sin(data->pl->ap) * MV);
	return (0);
}
