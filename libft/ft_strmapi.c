/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:54:45 by shikwon           #+#    #+#             */
/*   Updated: 2022/11/28 11:39:04 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	int		i;
	char	*new_s;

	if (!s || !f)
		return (NULL);
	new_s = (char *)ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!new_s)
		return (0);
	i = 0;
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	return (new_s);
}
/*
char	add_i(unsigned int i, char c)
{
	return (i + c);
}

int	main(void)
{
	char	str[] = "Hellooooo Bonjouuuurrr!";

	printf("%s", ft_strmapi(str, add_i));
}*/
