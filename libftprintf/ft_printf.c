/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:33:09 by shikwon           #+#    #+#             */
/*   Updated: 2023/08/05 16:25:23 by shikwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_specifiers(char c, va_list args)
{
	unsigned long long	p;

	if (c == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, int), c));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_uputnbr(va_arg(args, unsigned long int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'p')
	{
		p = va_arg(args, unsigned long long);
		if (p == 0)
			return (ft_putstr("(nil)"));
		else
			return (ft_putstr("0x") + ft_putpointer(p));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		sum;

	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	sum = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				break ;
			sum += ft_specifiers(str[i], args);
		}
		else
			sum += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (sum);
}
