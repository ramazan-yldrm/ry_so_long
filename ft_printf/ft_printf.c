/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:17:31 by ryildiri          #+#    #+#             */
/*   Updated: 2025/08/04 18:43:51 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

static int	type_frmt(va_list args, char c)
{
	int	a;
	int	b;

	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_puthex(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsig(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthexlow(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_puthexup(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	a = ft_putchar('%');
	b = ft_putchar(c);
	if (a == -1 || b == -1)
		return (-1);
	return (a + b);
}

int	ft_printf(const char *frmt, ...)
{
	unsigned int	i;
	int				len;
	int				swp;
	va_list			args;

	if (!frmt)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, frmt);
	while (frmt[i])
	{
		if (frmt[i + 1] != '\0' && frmt[i] == '%')
			swp = type_frmt(args, frmt[++i]);
		else
			swp = ft_putchar(frmt[i]);
		if (swp == -1)
			return (-1);
		len += swp;
		i++;
	}
	va_end(args);
	return (len);
}
