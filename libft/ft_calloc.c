/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:58:44 by shikwon           #+#    #+#             */
/*   Updated: 2022/12/01 20:03:17 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tmp;

	if (nmemb == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	if (nmemb > 0 && size != nmemb * size / nmemb)
		return (NULL);
	tmp = malloc(nmemb * size);
	if (tmp == NULL)
		return (NULL);
	ft_memset(tmp, 0, nmemb * size);
	return (tmp);
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int		main(int argc, const char *argv[])
{
	char	*str;

	alarm(5);
	if (argc == 1)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		str = (char *)ft_calloc(30, sizeof(char));
		if (!str)
			write(1, "NULL", 4);
		else
			write(1, str, 30);
		free(str);
	}
	
	printf("type: %d\n", sizeof(char)); // size_t nmemb;
	printf("type: %d\n", sizeof(int)); // size_t nmemb;
	printf("type: %d\n", sizeof(long)); // size_t nmemb;

	return (0);
}*/
