/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:10:07 by shikwon           #+#    #+#             */
/*   Updated: 2022/12/02 20:33:05 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	char	s1[] = "ABCDEFG";
	char	s2[] = "123456";

	t_list	*lst;
	t_list	*new;
	
	lst = ft_lstnew(s1);
	lst2 = ft_lstadd_front(s2);
	lst2 = lst->next;
}*/
