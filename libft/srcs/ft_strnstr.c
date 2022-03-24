/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:23:27 by gsap              #+#    #+#             */
/*   Updated: 2021/05/23 10:36:26 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*lieu;
	char	*obj;
	size_t	i;
	size_t	j;

	obj = (char *)needle;
	lieu = (char *)haystack;
	i = 0;
	if (obj[i] == 0)
		return (lieu);
	while (i < len && lieu[i])
	{
		j = 0;
		while (lieu[i + j] == obj[j] && i + j < len)
		{
			if (obj[j + 1] == '\0')
				return (&lieu[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
