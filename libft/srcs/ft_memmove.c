/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:49:43 by gsap              #+#    #+#             */
/*   Updated: 2021/05/23 15:38:44 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*from;
	unsigned char	*to;

	i = 0;
	from = (unsigned char *)src;
	to = (unsigned char *)dst;
	if (from == 0 && to == 0)
		return (NULL);
	if (to > from)
		while (len-- > 0)
			to[len] = from[len];
	else
	{
		while (i < len)
		{
			to[i] = from[i];
			i++;
		}
	}
	return (dst);
}
