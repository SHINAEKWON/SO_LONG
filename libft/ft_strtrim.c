/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:54:01 by shikwon           #+#    #+#             */
/*   Updated: 2022/11/26 11:53:22 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_istrim(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	int				end;
	size_t			len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (ft_istrim(s1[start], set) == 1)
		++start;
	end = ft_strlen(s1) - 1;
	while (ft_istrim(s1[end], set) == 1 && end >= 0)
		--end;
	if (end < 0)
		return ((char *)ft_calloc(1, 1));
	len = (size_t)end - (size_t)start + 1;
	return (ft_substr(s1, start, len));
}
/*#include <stdio.h>

int	main(void)
{
	char s1[] = "KWON shin AeK";
	char set[] = " ";

	printf("%s\n",ft_strtrim(s1, set));
}*/
