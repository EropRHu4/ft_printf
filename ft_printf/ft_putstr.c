/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syule <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:16:09 by syule             #+#    #+#             */
/*   Updated: 2022/01/08 16:17:54 by syule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *c)
{
	size_t	len;

	len = 0;
	if (!c)
		return (0);
	while (c[len])
		++len;
	return (len);
}

int	ft_putstr(char *s)
{
	size_t	n;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	n = ft_strlen(s);
	write(1, s, n);
	return (n);
}
