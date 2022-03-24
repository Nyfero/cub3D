/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 08:49:41 by gsap              #+#    #+#             */
/*   Updated: 2022/03/19 18:55:07 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_read_file(int fd, char *buf, char *tmp)
{
	long int	rd;

	rd = read(fd, buf, 1);
	if (rd == 0)
	{
		free(tmp);
		return (NULL);
	}
	buf[rd] = 0;
	while ((ft_check_new_line(buf) == -1) && rd > 0)
	{
		tmp = ft_strjoin_and_free_s1(tmp, buf);
		if (!tmp)
			return (NULL);
		rd = read(fd, buf, 1);
		buf[rd] = 0;
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		buf[2];

	if ((read(fd, buf, 0) == -1))
		return (NULL);
	tmp = ft_strdup("");
	if (!tmp)
		return (NULL);
	tmp = ft_read_file(fd, buf, tmp);
	if (!tmp)
		return (NULL);
	return (tmp);
}

int	ft_check_new_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
