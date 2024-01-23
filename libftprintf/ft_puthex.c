/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:13:20 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/05 16:05:03 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_count_digit(unsigned long long nb)
{
	int	i;

	i = 1;
	while (nb >= 16)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int	ft_putnbr_base(unsigned long long nb, char *base)
{
	if (nb >= 16)
		ft_putnbr_base((nb / 16), base);
	ft_putchar(base[nb % 16]);
	return (ft_count_digit(nb));
}

int	ft_puthex(int i, char x)
{
	unsigned int	ui;
	int				sum;
	char			*base;

	ui = (unsigned int)i;
	sum = 0;
	base = "0123456789abcdef";
	if (x == 'X')
		base = "0123456789ABCDEF";
	ft_putnbr_base(ui, base);
	sum = sum + ft_count_digit(ui);
	return (sum);
}

int	ft_putpointer(unsigned long long nb)
{
	char	*base;
	int		sum;

	base = "0123456789abcdef";
	sum = 0;
	ft_putnbr_base(nb, base);
	sum += ft_count_digit(nb);
	return (sum);
}
