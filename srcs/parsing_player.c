/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:01:57 by gsap              #+#    #+#             */
/*   Updated: 2022/04/01 12:27:06 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_player_info(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
				if (place_player(data, i, j))
					return (1);
		}
	}
	if (!data->pl->xp || !data->pl->yp)
		return (error_player());
	return (0);
}

int	place_player(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'N' && !data->pl->xp)
		data->pl->ap = 3.1415926535 / 2;
	else if (data->map[i][j] == 'S' && !data->pl->xp)
		data->pl->ap = 3 * 3.1415926535 / 2;
	else if (data->map[i][j] == 'E' && !data->pl->xp)
		data->pl->ap = 3.1415926535;
	else if (data->map[i][j] == 'W' && !data->pl->xp)
		data->pl->ap = 0;
	else
		return (error_file(10));
	data->pl->xp = j * data->size + data->size / 2;
	data->pl->yp = i * data->size + data->size / 2;
	data->pl->dxp = (cos(data->pl->ap) * MV);
	data->pl->dyp = (sin(data->pl->ap) * MV);
	return (0);
}
