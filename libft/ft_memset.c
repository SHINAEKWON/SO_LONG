/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:48:25 by shikwon           #+#    #+#             */
/*   Updated: 2022/11/24 11:34:29 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)s + i) = c;
		i++;
	}
	return (s);
}
/*
A VOIR : CASTER EN UNSIGNED CHAR

int	main(void)
{
	char	s1[] = "Doremifa";
	char	s1[] = "\0";
	char	s1[] = NULL;
	char	s2[] = "Doremifa";

	printf("before memset: %s\n", s1);
	memset(s1, 65, 5);
	printf("after memset:  %s\n\n", s1);
	printf("before ft_memset: %s\n", s2);
	ft_memset(s2, 65, 5);
	printf("after ft_memset:  %s\n", s2);
}*/
