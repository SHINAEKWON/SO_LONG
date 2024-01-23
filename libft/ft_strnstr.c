/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:01:40 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/28 23:49:00 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*big_tmp;

	i = 0;
	j = 0;
	if (!big && !len)
		return (NULL);
	big_tmp = (char *)big;
	if (*little == 0)
		return (big_tmp);
	while (big_tmp[i] && len > 0)
	{
		j = 0;
		if (big_tmp[i] == little[j])
		{
			while (j < len && little[j] && big_tmp[i + j] == little[j])
				j++;
			if (little[j] == 0)
				return (&big_tmp[i]);
		}
		i++;
		len--;
	}
	return (NULL);
}
// #include <bsd/string.h>
// #include <stdio.h>

// int	main(int ac, char **av, char **env)
// {
// 	char s1[] = "0";
// 	char s2[] = "Display";
// 	char *strnstr_res;
// 	char *ft_strnstr_res;
// 	(void)ac;
// 	(void)av;
// 	strnstr_res = strnstr(s1, s2, 10);
// 	ft_strnstr_res = ft_strnstr(s1, s2, 10);
// 	printf("str :%s\nto find : %s\n", s1, s2);
// 	printf("strnstr ='%s'\n", strnstr(s1, s2, 10));
// 	printf("ft_strnstr ='%s'\n", ft_strnstr(s1, s2, 10));
// 	printf("Double Check : %s\n", strnstr_res == ft_strnstr_res?"OK":"FAIL");
// }
