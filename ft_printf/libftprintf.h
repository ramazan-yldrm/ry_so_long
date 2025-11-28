/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:34:38 by ryildiri          #+#    #+#             */
/*   Updated: 2025/08/03 12:29:52 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_puthex(void *p);
int	ft_putnbr(int n);
int	ft_putnbr_unsig(unsigned int n);
int	ft_puthexlow(unsigned int n);
int	ft_puthexup(unsigned int n);

#endif
