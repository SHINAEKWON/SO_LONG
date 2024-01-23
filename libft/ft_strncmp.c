/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:02:37 by shikwon           #+#    #+#             */
/*   Updated: 2022/11/14 11:45:09 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i]) && (s1[i] == s2[i]) && n > 0)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s1[] = "abcdABC";
	char s2[] = "abcdabc";

	printf("strncmp   >>\ns1:%s\ns2:%s\nstrncmp:%d\n\n",
       	s1, s2, strncmp(s1, s2, 5));
	printf("ft_strncmp>>\ns1:%s\ns2:%s\nft_strncmp:%d\n",
       	s1, s2, ft_strncmp(s1, s2, 5));
}*/
