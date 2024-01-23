/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:40:17 by shikwon           #+#    #+#             */
/*   Updated: 2022/11/28 14:03:55 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char*))
{
	int	i;

	i = 0;
	if (f == NULL || s == NULL)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void	del(unsigned int a, char *b)
{
	*b = 'a';
	(void) a;
}

int	main(void)
{
	char	str[20] = "hello World";

	printf("%s\n", str);
	ft_striteri(str, del);
	printf("%s\n", str); 	
}
*/
