/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:18:01 by ryildiri          #+#    #+#             */
/*   Updated: 2025/08/06 15:24:53 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_recnbr(int n)
{
	int	len;
	int	swp;

	len = 0;
	if (n > 9)
	{
		swp = ft_putnbr(n / 10);
		if (swp == -1)
			return (-1);
		len += swp;
		swp = ft_putnbr(n % 10);
		if (swp == -1)
			return (-1);
		len += swp;
	}
	else
	{
		swp = ft_putchar(n + '0');
		if (swp == -1)
			return (-1);
		len += swp;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;
	int	swp;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		swp = ft_putchar('-');
		if (swp == -1)
			return (-1);
		len += swp;
		n = -n;
	}
	swp = ft_recnbr(n);
	if (swp == -1)
		return (-1);
	len += swp;
	return (len);
}
