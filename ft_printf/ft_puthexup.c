/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:17:54 by ryildiri          #+#    #+#             */
/*   Updated: 2025/08/03 12:30:24 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthexup(unsigned int n)
{
	int	len;
	int	swp;

	len = 0;
	if (n > 15)
	{
		swp = ft_puthexup(n / 16);
		if (swp == -1)
			return (-1);
		len += swp;
		swp = ft_puthexup(n % 16);
		if (swp == -1)
			return (-1);
		len += swp;
	}
	else
	{
		swp = ft_putchar("0123456789ABCDEF"[n]);
		if (swp == -1)
			return (-1);
		len += swp;
	}
	return (len);
}
