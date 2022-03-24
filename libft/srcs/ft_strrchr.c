/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:12:11 by gsap              #+#    #+#             */
/*   Updated: 2022/03/15 17:42:40 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (str[i])
		i++;
	while (str[i] != (char)c)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return (&str[i]);
}
