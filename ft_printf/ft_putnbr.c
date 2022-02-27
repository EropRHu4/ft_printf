/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syule <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:14:25 by syule             #+#    #+#             */
/*   Updated: 2022/01/08 16:18:10 by syule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr(char *s);

int	ft_putnbr(int n)
{
	char		num[11];
	int			i;
	long long	tmp;
	int			res;

	res = 0;
	tmp = n;
	if (tmp == 0)
		return (write(1, "0", 1));
	if (tmp < 0)
	{
		res += write(1, "-", 1);
		tmp *= -1;
	}
	i = 10;
	num[i--] = '\0';
	while (tmp != 0)
	{
		num[i--] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (res + ft_putstr(num + i + 1));
}
