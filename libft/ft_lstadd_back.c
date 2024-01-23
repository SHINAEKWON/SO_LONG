/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:29:22 by shikwon           #+#    #+#             */
/*   Updated: 2022/11/29 20:05:37 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*back;

	if (list)
	{
		if (*list)
		{
			back = ft_lstlast(*list);
			back->next = new;
		}
		else
			*list = new;
	}
}
/*
int	main(void)
{


}*/
