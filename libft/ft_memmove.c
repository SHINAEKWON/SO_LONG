/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:21:57 by shikwon           #+#    #+#             */
/*   Updated: 2022/11/14 11:15:52 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i)
		{
			((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char src[20] = "Doremifasol arirang";
	char src1[20] = "Doremifasol arirang";
	char dest[] = "00000000000000000000000";
	char dest1[] = "00000000000000000000000";

	printf("src before memcpy: %s\n",src);
	printf("dest before memcpy: %s\n",dest);
	memmove(dest, src, 5);
	printf("\nsrc after memcpy: %s\n", src);
	printf("dest after memcpy: %s\n", dest);

	printf("\n\nsrc before ft_memcpy: %s\n",src1);
	printf("dest before ft_memcpy: %s\n",dest1);
	ft_memmove(dest1, src1, 5);
	printf("\nsrc after ft_memcpy: %s\n", src1);
	printf("dest after ft_memcpy: %s\n\n", dest1);
	printf("double check : %s", dest == dest1 ? "OK" : "FAIL");

}*/
