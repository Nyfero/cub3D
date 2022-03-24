/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:46:42 by gsap              #+#    #+#             */
/*   Updated: 2021/05/23 15:37:47 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*from;
	unsigned char	*to;

	i = 0;
	from = (unsigned char *)src;
	to = (unsigned char *)dst;
	if (from == 0 && to == 0)
		return (NULL);
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (dst);
}
