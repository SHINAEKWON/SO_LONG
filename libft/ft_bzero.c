/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:14:39 by shikwon           #+#    #+#             */
/*   Updated: 2022/11/14 11:50:54 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_tmp;
	size_t			i;

	i = 0;
	s_tmp = (unsigned char *)s;
	while (i < n)
	{
		*((char *)s_tmp + i) = 0;
		i++;
	}
}
/*
int	main(void)
{
	char str[40] = "If Shin Ae ate all your tamarinds";
	char str1[40] = "If Shin Ae ate all your tamarinds";

	printf ("before ft_bzero: %s\n", str);
	ft_bzero(str, sizeof(str) - 1);
	printf ("after ft_bzero: %s\n\n", str);
	printf ("before bzero: %s\n", str1);
	bzero(str1, sizeof(str1) - 1);
	printf("after bzero: %s\n", str1);
}*/
