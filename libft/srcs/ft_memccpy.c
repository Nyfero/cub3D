/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:37:42 by gsap              #+#    #+#             */
/*   Updated: 2021/05/22 10:49:34 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*from;
	unsigned char	*to;

	i = 0;
	from = (unsigned char *)src;
	to = (unsigned char *)dst;
	while (i < n)
	{
		to[i] = from[i];
		if (from[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
