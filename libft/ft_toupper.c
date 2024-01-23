/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:47:41 by shikwon           #+#    #+#             */
/*   Updated: 2022/11/11 20:02:36 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
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
	printf("toupper>>\n");
	printf("%s\n", str1);
	while (str1[i])
	{
		printf("%c", toupper(str1[i]));
		i++;
	}
	i = 0;
	printf("\nft_toupper>>\n");
	printf("%s\n", str2);
	while (str2[i])
	{
		printf("%c", ft_toupper(str2[i]));
		i++;
	}
}*/
