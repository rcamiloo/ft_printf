/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:49:18 by lcandido          #+#    #+#             */
/*   Updated: 2020/07/15 19:20:49 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_pct(t_flags *flags, va_list args)
{
	int		count;

	ft_printf_star(flags, args);
	count = 0;
	if (flags->minus)
		count += ft_putchar('%');
	count += padding(flags->width - 1, flags->zero ? '0' : ' ');
	if (!flags->minus)
		count += ft_putchar('%');
	return (count);
}
