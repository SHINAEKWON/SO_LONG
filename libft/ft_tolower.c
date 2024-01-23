/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:47:41 by shikwon           #+#    #+#             */
/*   Updated: 2022/11/11 20:15:45 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char str1[] = "123456789 abcDEFghiJKL !@#$%^&*(";
	char str2[] = "123456789 abcDEFghiJKL !@#$%^&*(";
	int	i;

	i = 0;
	printf("tolower>>\n");
	printf("%s\n", str1);
	while (str1[i])
	{
		printf("%c", tolower(str1[i]));
		i++;
	}
	i = 0;
	printf("\nft_tolower>>\n");
	printf("%s\n", str2);
	while (str2[i])
	{
		printf("%c", ft_tolower(str2[i]));
		i++;
	}
}*/
