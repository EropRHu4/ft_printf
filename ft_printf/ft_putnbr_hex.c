/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syule <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:14:59 by syule             #+#    #+#             */
/*   Updated: 2022/01/08 16:17:26 by syule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long long nbr, char *base)
{
	int					res;
	int					i;
	char				n[32];
	unsigned long long	tmp;

	tmp = nbr;
	i = 0;
	res = 0;
	while (tmp > 0)
	{
		n[i++] = base[tmp % 16];
		tmp /= 16;
	}
	if (nbr == 0)
		res += ft_putchar(*base);
	else
		while (i)
			res += ft_putchar(n[--i]);
	return (res);
}
