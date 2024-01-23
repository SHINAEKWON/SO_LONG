/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:18:10 by shikwon           #+#    #+#             */
/*   Updated: 2022/11/14 14:03:30 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return ((void *)0);
}
/*
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	char *result;
	char *result2;

	if (ac != 2)
		printf("Usage: %s string\n", av[0]);
	else
	{
		result = (char *)memchr(av[1], 'x', strlen(av[1]));
		result2 = (char *)ft_memchr(av[1], 'x', strlen(av[1]));
		if (result != NULL && result2 != NULL)
		{
			printf("memchr:       The string starting with x is %s\n", result);
			printf("ft_memchr:    The string starting with x is %s\n", result2);
			printf("double check :%s\n", result == result2 ? "OK" : "FAIL");
		}
		else
			printf("The letter x cannot be found in the string\n");
	}
}*/
