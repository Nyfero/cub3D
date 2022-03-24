/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 11:20:51 by gsap              #+#    #+#             */
/*   Updated: 2021/05/22 14:49:38 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*one;
	const unsigned char	*two;

	if (s1 == s2 || n == 0)
		return (0);
	one = (const unsigned char *)s1;
	two = (const unsigned char *)s2;
	while (n--)
	{
		if (*one != *two)
			return (*one - *two);
		if (n)
		{
			one++;
			two++;
		}
	}
	return (0);
}
