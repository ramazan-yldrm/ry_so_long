/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsig.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:17:58 by ryildiri          #+#    #+#             */
/*   Updated: 2025/08/03 12:30:32 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_unsig(unsigned int n)
{
	int	len;
	int	swp;

	len = 0;
	if (n < 10)
	{
		swp = ft_putchar(n + '0');
		if (swp == -1)
			return (-1);
		len += swp;
	}
	else
	{
		swp = ft_putnbr_unsig(n / 10);
		if (swp == -1)
			return (-1);
		len += swp;
		swp = ft_putnbr_unsig(n % 10);
		if (swp == -1)
			return (-1);
		len += swp;
	}
	return (len);
}
