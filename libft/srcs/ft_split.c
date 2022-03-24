/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:35:41 by gsap              #+#    #+#             */
/*   Updated: 2022/03/09 15:08:41 by jgourlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	**ft_alloc_tab(char const *s, char c)
{
	size_t	i;
	char	**tab;

	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
			if (*s++)
				i++;
		while (*s && (*s != c))
			s++;
	}
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	tab[i] = NULL;
	return (tab);
}

static void	*ft_free_split(char **split, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(split[j]);
		j++;
	}
	free(split);
	return (NULL);
}

static char	*ft_assign_tab(char const *s, char *tab, size_t i)
{
	tab[i] = '\0';
	s--;
	while (i > 0)
		tab[--i] = *s--;
	return (tab);
}

static char	**ft_split_tab(char const *s, char c, char **split)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (*s)
	{
		i = 0;
		while (*s && (*s == c))
			s++;
		while (*s && (*s != c))
		{
			i++;
			s++;
		}
		if (i > 0)
		{
			split[j] = (char *)malloc(sizeof(char) * (i + 1));
			if (!split[j])
				return (ft_free_split(split, j));
			split[j] = ft_assign_tab(s, split[j], i);
			j++;
		}
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;

	if (!s)
		return (NULL);
	tab = ft_alloc_tab(s, c);
	if (!tab)
		return (NULL);
	tab = ft_split_tab(s, c, tab);
	if (!tab)
		return (NULL);
	return (tab);
}
