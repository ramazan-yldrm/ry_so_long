/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:18:05 by ryildiri          #+#    #+#             */
/*   Updated: 2025/08/03 12:30:44 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *s)
{
	unsigned int	i;
	int				swp;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
	{
		swp = ft_putchar(s[i]);
		if (swp == -1)
			return (-1);
		i++;
	}
	return (i);
}
