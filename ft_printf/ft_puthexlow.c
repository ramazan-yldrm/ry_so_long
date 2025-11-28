/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:17:51 by ryildiri          #+#    #+#             */
/*   Updated: 2025/08/03 12:30:19 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthexlow(unsigned int n)
{
	int	len;
	int	swp;

	len = 0;
	if (n > 15)
	{
		swp = ft_puthexlow(n / 16);
		if (swp == -1)
			return (-1);
		len += swp;
		swp = ft_puthexlow(n % 16);
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
