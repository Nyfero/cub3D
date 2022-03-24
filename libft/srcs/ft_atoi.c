/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 08:41:32 by gsap              #+#    #+#             */
/*   Updated: 2022/02/24 11:36:37 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

long int	long_value(int j, unsigned long long int res)
{
	if (res > 9223372036854775807)
	{
		if (j < 0)
			return (0);
		else
			return (-1);
	}
	else
		return (res * j);
}

long int	ft_atoi(const char *str)
{
	int						j;
	unsigned long long int	res;

	j = 1;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			j *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - 48);
	return (long_value(j, res));
}
