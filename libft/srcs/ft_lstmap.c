/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsap <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:05:58 by gsap              #+#    #+#             */
/*   Updated: 2021/05/27 17:57:19 by gsap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void	*ft_clear1(t_list *lst, void (*del)(void *))
{
	ft_lstclear(&lst, del);
	return (NULL);
}

static void	*ft_clear2(t_list *lst, t_list *cpy, void (*del)(void *))
{
	ft_lstclear(&lst, del);
	ft_lstclear(&cpy, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = ft_lstnew((*f)(lst->content));
	if (!tmp)
		return (ft_clear1(lst, del));
	cpy = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
			return (ft_clear2(lst, cpy, del));
		ft_lstadd_back(&cpy, tmp);
		lst = lst->next;
	}
	return (cpy);
}
