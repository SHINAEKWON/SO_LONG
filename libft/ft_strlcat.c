/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:52:50 by shikwon           #+#    #+#             */
/*   Updated: 2023/07/27 19:20:42 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_l;
	size_t	src_l;
	size_t	i;

	if ((!dst || !src) && size == 0)
		return (size);
	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_l);
	if (size == 0 && src == 0)
		return (0);
	while (src[i] && (dst_l + i) < (size - 1))
	{
		dst[dst_l + i] = src[i];
		i++;
	}
	if (dst_l + i < size)
		dst[dst_l + i] = '\0';
	if (dst_l > size)
		return (src_l + size);
	return (src_l + dst_l);
}
/*

#include <stdio.h>
#include <bsd/string.h>

int     main(void)
{
        char src[] = "Homejack a strawberry!";
        char dest[] = "I do love";
        char src1[] = "Homejack a strawberry!";
        char dest1[] = "I do love";

        printf("src :%s-%zu\n", src, ft_strlen(src));
        printf("dest:%s-%zu\n", dest, ft_strlen(dest));

	printf("ft_strlcat>>\n");
        printf("%zu\n", ft_strlcat(src, dest, 5));

        printf("\nstrlcat>>\n");
        printf("%zu\n", strlcat(src1, dest1, 5));

        printf("\nDouble check\n");
        printf("%zu vs %zu", ft_strlcat(src, dest, 5), strlcat(src, dest, 5));
        printf("->%s", ft_strlcat(src, dest, 5) == strlcat(src, dest, 5)?
       	"OK":"FAIL");
}*/
