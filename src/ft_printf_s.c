/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilo <camilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:38:47 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/24 02:10:44 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_s(t_flags *flags, va_list args)
{
	int		count;
	char	*str;
	int		size;
	int		pad_size;

	ft_printf_star(flags, args);
	str = va_arg(args, char *);
	count = 0;
	if (flags->point == 0 && flags->width == 0)
		return (0);
	if (str == NULL)
		str = "(null)";
	size = (flags->point > ft_strlen(str) || flags->point == -1)
			? ft_strlen(str) : flags->point;
	pad_size = flags->width - size;
	if (!flags->minus)
		count += padding(pad_size, flags->zero ? '0' : ' ');
	while (size-- && *str)
		count += ft_putchar(*str++);
	if (flags->minus)
		count += padding(pad_size, ' ');
	return (count);
}
