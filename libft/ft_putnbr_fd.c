/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:14:13 by shikwon           #+#    #+#             */
/*   Updated: 2022/11/16 09:42:48 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbp;

	if (n < 0)
	{
		nbp = n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		nbp = n;
	if (nbp >= 10)
	{
		ft_putnbr_fd(nbp / 10, fd);
	}
	ft_putchar_fd((nbp % 10) + '0', fd);
}
/*
int	main(void)
{
	int	a = 2147483647;
	
	ft_putnbr_fd(a, 1);
}*/
