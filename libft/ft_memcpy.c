/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:59:08 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/03 09:23:59 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char src[] = "haha anyeong";
	char dest[30] = "abcdefghijkl";

	printf("src:\n%s\n", src);
	printf("dest:\n%s\n", dest);
	ft_memcpy(dest, src, 4);
	printf("src: \n%s\n", src);
	printf("dest: \n%s\n", dest);
}*/
