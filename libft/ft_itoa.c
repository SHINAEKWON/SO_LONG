/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:58:43 by shikwon           #+#    #+#             */
/*   Updated: 2023/07/29 16:15:41 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nb_digit(int n)
{
	long int	nbr;
	int			size;

	nbr = n;
	size = 1;
	if (nbr < 0)
	{
		while (nbr / 10)
		{
			nbr = nbr / 10;
			size++;
		}
		size++;
		nbr = nbr * -1;
	}
	else if (nbr > 0)
	{
		while (nbr / 10)
		{
			nbr = nbr / 10;
			size++;
		}
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	int			i;
	int			neg;
	char		*str;

	neg = 0;
	nbr = n;
	i = nb_digit(nbr) - 1;
	str = (char *)ft_calloc(nb_digit(nbr) + 1, sizeof(char));
	if (str == 0)
		return (0);
	if (nbr < 0)
	{
		neg = 1;
		nbr *= -1;
		str[0] = '-';
	}
	while (i >= neg)
	{
		str[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%s", ft_itoa(ft_atoi(av[1])));
	}
	return (0);
}*/
