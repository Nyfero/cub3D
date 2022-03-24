/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:15:19 by gsap              #+#    #+#             */
/*   Updated: 2022/03/16 16:54:01 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_is_sep(char c, char const *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	compt_deb(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_is_sep(s1[i], set))
		i++;
	return (i);
}

static int	compt_fin(char const *s1, char const *set)
{
	size_t	compt;
	size_t	i;

	compt = 0;
	i = ft_strlen(s1) - 1;
	while (i > 0 && ft_is_sep(s1[i], set))
	{
		compt++;
		i--;
	}
	return (compt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		x;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	else
	{
		i = compt_deb(s1, set);
		x = compt_fin(s1, set);
		if ((i - x) < (int)ft_strlen(s1))
			str = ft_substr(s1, i, ft_strlen(s1) - (i + x));
		else
			return (ft_strdup(s1));
	}
	return (str);
}
