/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:17:49 by ryildiri          #+#    #+#             */
/*   Updated: 2025/08/06 15:23:59 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_rechex(unsigned long n)
{
	int	len;
	int	swp;

	len = 0;
	if (n > 15)
	{
		swp = ft_rechex(n / 16);
		if (swp == -1)
			return (-1);
		len += swp;
		swp = ft_rechex(n % 16);
		if (swp == -1)
			return (-1);
		len += swp;
	}
	else
	{
		swp = ft_putchar("0123456789abcdef"[n]);
		if (swp == -1)
			return (-1);
		len += swp;
	}
	return (len);
}

int	ft_puthex(void *p)
{
	int	len;
	int	swp;

	len = 0;
	if (!p)
		return (ft_putstr("(nil)"));
	swp = ft_putstr("0x");
	if (swp == -1)
		return (-1);
	len += swp;
	swp = ft_rechex((unsigned long)p);
	if (swp == -1)
		return (-1);
	len += swp;
	return (len);
}
