/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free_s2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:29:50 by gsap              #+#    #+#             */
/*   Updated: 2021/06/29 15:38:48 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin_and_free_s2(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	char	*strcopie;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	strcopie = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!strcopie)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		strcopie[i] = s1[i];
	while ((i - len_s1) < len_s2)
	{
		strcopie[i] = s2[(i - len_s1)];
		i++;
	}
	strcopie[i] = 0;
	free(s2);
	return (strcopie);
}
