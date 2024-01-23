/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:08:05 by shikwon           #+#    #+#             */
/*   Updated: 2022/11/29 13:44:33 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*value;

	value = (t_list *)malloc(sizeof(t_list));
	if (!value)
		return (value = NULL);
	value->next = NULL;
	value->content = content;
	return (value);
}
/*
int	main(void)
{
	char s[] = "Hello Bonjour Annyeong?";
	
	printf("%s\n",(char *)ft_lstnew(s)->content);
	printf ("%s",(char*)ft_lstnew("")->content);	
}*/
