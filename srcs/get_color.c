/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:46:01 by gsap              #+#    #+#             */
/*   Updated: 2022/04/01 15:52:48 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_red(char *line)
{
	int	r;

	r = ft_atoi(line);
	if (r >= 256)
		return (-2);
	return (r);
}

int	get_green(char *line)
{
	int	g;

	g = ft_atoi(line);
	if (g >= 256)
		return (-2);
	return (g);
}

int	get_blue(char *line)
{
	int	b;

	b = ft_atoi(line);
	if (b >= 256)
		return (-2);
	return (b);
}
