/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:14:17 by shikwon           #+#    #+#             */
/*   Updated: 2022/11/29 20:37:12 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	char	s1[] = "Doremifa";
	char	s2[] = "Salsa4Life";

	t_list	*lst;
	t_list	*new;

	lst = NULL;
	new = ft_lstnew(s1);
	ft_lstadd_front(&lst, new);
	if (ft_memcmp(lst->content, new->content, sizeof(new->content) != 0))
		printf("Error\n");
	else
		printf("OK\n");

	new = ft_lstnew(s2);
	ft_lstadd_front(&lst, new);
	if (ft_memcmp(lst->content, new->content, sizeof(new->content) != 0))
		printf("Error\n");
	else
		printf("OK\n");
	return (0);
}*/
