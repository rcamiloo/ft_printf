/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpraca-a <kpraca-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:55:08 by kpraca-a          #+#    #+#             */
/*   Updated: 2020/05/02 17:28:38 by kpraca-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
int	ft_printf(const char *fmt, ...)
{
	va_list	args;

	va_start(args, fmt);
	while (*fmt)
	{
		//printf("\nTestando %s\n" , fmt);
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == ' ')
				ft_putchar_fd(*fmt, 1);
			while (*fmt == ' ')
				fmt++;
			if (*fmt == 'd')
				ft_putnbr_fd(va_arg(args, int), 1);
		}
		else
			ft_putchar_fd(*fmt, 1);
		fmt++;
	}
	va_end(args);
	return (0);
}
