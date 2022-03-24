/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:59:19 by gsap              #+#    #+#             */
/*   Updated: 2021/06/03 10:46:36 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*strcopie;

	if (!s1 || !s2)
		return (NULL);
	k = ft_strlen(s1) + ft_strlen(s2);
	strcopie = (char *)malloc(sizeof(char) * (k + 1));
	if (!strcopie)
		return (NULL);
	i = 0;
	j = 0;
	while (i < k)
	{
		while (i < ft_strlen(s1))
		{
			strcopie[i] = s1[i];
			i++;
		}
		while (j < ft_strlen(s2))
			strcopie[i++] = s2[j++];
	}
	strcopie[i] = '\0';
	return (strcopie);
}
