/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:51:31 by shikwon           #+#    #+#             */
/*   Updated: 2022/12/01 18:52:12 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*pos_new;
	t_list	*pos_old;

	if (!lst)
		return (NULL);
	new_lst = ft_lstnew((*f)(lst->content));
	if (!new_lst)
		return (NULL);
	pos_new = new_lst;
	pos_old = lst->next;
	while (pos_old)
	{
		pos_new->next = ft_lstnew((*f)(pos_old->content));
		if (!pos_new->next)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		pos_new = pos_new->next;
		pos_old = pos_old->next;
	}
	return (new_lst);
}
