/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syule <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:12:48 by syule             #+#    #+#             */
/*   Updated: 2022/01/09 13:22:50 by syule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parser(const char *str, int i, va_list *ptr)
{
	int					count;
	unsigned long long	p;

	i++;
	if (str[i] == 'c')
		count = ft_putchar((char)va_arg(*ptr, int));
	if (str[i] == 's')
		count = ft_putstr(va_arg(*ptr, char *));
	if (str[i] == 'd' || str[i] == 'i')
			count = ft_putnbr(va_arg(*ptr, int));
	if (str[i] == 'x')
		count = ft_putnbr_hex(va_arg(*ptr, unsigned int), "0123456789abcdef");
	if (str[i] == 'X')
		count = ft_putnbr_hex(va_arg(*ptr, unsigned int), "0123456789ABCDEF");
	if (str[i] == 'u')
		count = ft_putnbr_uns(va_arg(*ptr, unsigned int));
	if (str[i] == 'p')
	{
		p = (unsigned long long)va_arg(*ptr, void *);
		write(1, "0x", 2);
		count = ft_putnbr_hex(p, "0123456789abcdef") + 2;
	}
	if (str[i] == '%')
		count = write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		res;

	i = 0;
	va_start(ptr, str);
	res = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			res += parser(str, i++, &ptr);
		}
		else
			res += ft_putchar(str[i]);
		++i;
	}
	va_end(ptr);
	return (res);
}
