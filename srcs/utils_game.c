/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:45:40 by jgourlin          #+#    #+#             */
/*   Updated: 2022/03/31 13:48:30 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_utils_game_change(t_data *d, float temp_x, float temp_y)
{
	d->pl->xp -= temp_x;
	d->pl->yp -= temp_y;
}
