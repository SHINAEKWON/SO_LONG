/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:48:27 by shikwon           #+#    #+#             */
/*   Updated: 2022/12/03 12:45:25 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;

	i = 0;
	s1_tmp = (unsigned char *)s1;
	s2_tmp = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_tmp[i] != s2_tmp[i])
			return (s1_tmp[i] - s2_tmp[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	len;
	int	result;
	int	result2;

	if (ac != 3)
	{
		printf("Usage: %s string1 string2\n", av[0]);
	}
	else
	{
		if (strlen(av[1]) < strlen(av[2]))
			len = strlen(av[1]);
		else
			len = strlen(av[2]);

		result = memcmp(av[1], av[2], len);

		printf("memcmp:\nWhen the first %i characters are compared,\n", len);
		if (result == 0)
			printf("\"%s\" is identical to \"%s\"\n", av[1], av[2]);
		else if (result < 0)
			printf("\"%s\" is less than \"%s\"\n", av[1], av[2]);
		else
			printf("\"%s\" is greater than \"%s\"\n", av[1], av[2]);

		result2 = ft_memcmp(av[1], av[2], len);
		printf("\nft_memcmp:\nWhen the first %i characters are compared,\n", len);
		if (result2 == 0)
			printf("\"%s\" is identical to \"%s\"\n", av[1], av[2]);
		else if (result2 < 0)
			printf("\"%s\" is less than \"%s\"\n", av[1], av[2]);
		else
			printf("\"%s\" is greater than \"%s\"\n", av[1], av[2]);
	}
}*/
