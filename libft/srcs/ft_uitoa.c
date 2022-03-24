/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 10:46:09 by gsap              #+#    #+#             */
/*   Updated: 2021/07/01 16:42:59 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static long int	taille_tab(unsigned int nbr)
{
	long int	compt;

	compt = 1;
	while (nbr / 10 > 0)
	{
		nbr = nbr / 10;
		compt++;
	}
	return (compt);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	nb;
	long int		i;
	char			*str;

	nb = n;
	i = 0;
	i += taille_tab(nb);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = 0;
	i--;
	while (i >= 0)
	{
		str[i] = (nb % 10) + 48;
		nb = (nb / 10);
		i--;
	}
	return (str);
}
