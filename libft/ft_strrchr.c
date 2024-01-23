/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:56:33 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/28 21:30:46 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	tmp_c;
	char	*tmp_s;

	tmp_c = (char)c;
	tmp_s = (char *)s;
	if (tmp_c == '\0')
		return (&tmp_s[ft_strlen(tmp_s)]);
	i = ft_strlen(tmp_s) - 1;
	while (i >= 0)
	{
		if (tmp_s[i] == tmp_c)
			return (&tmp_s[i]);
		i--;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char s1[] = "abcdefghijklmnabcdefg";
	char c = 'c';

	printf("text     :%s\n", s1);
	printf("strchr   :%s\n", strrchr(s1, c));
	printf("ft_strchr:%s\n", ft_strrchr(s1, c));
}*/
