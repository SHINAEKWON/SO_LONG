/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:22:35 by shikwon           #+#    #+#             */
/*   Updated: 2022/12/01 20:10:52 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_s;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) - 1 < start)
	{
		new_s = (char *)ft_calloc(1, sizeof(char));
		return (new_s);
	}
	if (start + len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	new_s = (char *)ft_calloc(len + 1, sizeof(char));
	if (new_s == NULL)
		return (0);
	while (s[i] && len > 0)
	{
		new_s[i] = s[start];
		i++;
		start++;
		len--;
	}
	return (new_s);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_substr("FULL BULLSHIT", 400, 20));

	char * s = ft_strtrim("tripouille   xxx", " x");
	printf("%s", ft_substr("FULL BULLSHIT", 400, 20));

}*/
