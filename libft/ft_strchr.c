/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:20:11 by shikwon           #+#    #+#             */
/*   Updated: 2022/11/14 11:59:05 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	tmp_c;
	char	*tmp_s;

	i = 0;
	tmp_c = (char)c;
	tmp_s = (char *)s;
	while (tmp_s[i])
	{
		if (tmp_s[i] == tmp_c)
			return (&tmp_s[i]);
		i++;
	}
	if (tmp_s[i] == tmp_c)
		return (&tmp_s[i]);
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char s1[] = "abcdefghijklmn";
	char c = 'c';

	printf("text     :%s\n", s1);	
	printf("strchr   :%s\n", strchr(s1, c));
	printf("ft_strchr:%s\n", ft_strchr(s1, c));


}*/
