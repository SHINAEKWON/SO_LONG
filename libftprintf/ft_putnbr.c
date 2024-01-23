/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:39:13 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/05 16:05:10 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putnbr(int nb)
{
	int			count;
	long long	nbr;

	count = 0;
	nbr = (long long)nb;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (nbr < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr(-nbr);
	}
	else if (nbr < 10)
		count += ft_putchar(nbr + '0');
	else
	{
		count += ft_putnbr(nbr / 10);
		count += ft_putnbr(nbr % 10);
	}
	return (count);
}

int	ft_uputnbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (nb > 0 && nb <= 9)
	{
		count += ft_putchar(nb + '0');
		return (count);
	}
	else if (nb > 0)
	{
		count += ft_uputnbr(nb / 10);
		count += ft_uputnbr(nb % 10);
		return (count);
	}
	else
		return (0);
}
