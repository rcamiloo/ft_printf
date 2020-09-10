/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilo <camilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:38:47 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/08/20 20:30:38 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_printf_pa(t_flags *flags)
{
	int	count;

	count = 0;
	while (flags->width-- - 2 > 0)
		count += ft_putchar(' ');
	count += ft_printf("0x");
	return (count);
}

static int	ft_printf_pb(t_flags *flags, int len, char *end_hex)
{
	int	count;

	count = ft_printf("0x");
	while (flags->point-- - len)
		count += ft_putchar('0');
	count += ft_printf(end_hex);
	return (count);
}

static int	ft_printf_pc(t_flags *flags, int len, char *end_hex)
{
	int	count;
	int pad_size;

	count = 0;
	len = len + 2;
	pad_size = flags->width - len;
	if (!flags->minus)
		count += padding(pad_size, flags->zero ? '0' : ' ');
	count += ft_printf("0x%s", end_hex);
	if (flags->minus)
		count += padding(pad_size, ' ');
	return (count);
}

static int	ft_printf_pd(t_flags *flags, int len, char *end_hex)
{
	int	count;
	int pad_size;

	count = 0;
	pad_size = flags->width - flags->point;
	if (!flags->minus)
		count += padding(pad_size, ' ');
	count += ft_printf("0x") + padding(flags->point - len, '0')
			+ ft_printf(end_hex);
	if (flags->minus)
		count += padding(pad_size, ' ');
	return (count);
}

int			ft_printf_p(t_flags *flags, va_list args)
{
	int						count;
	int						len;
	char					*end_hex;
	unsigned long int		end_dec;

	ft_printf_star(flags, args);
	end_dec = va_arg(args, unsigned long int);
	end_hex = ft_itoa_base(end_dec, 'x');
	count = 0;
	len = ft_strlen(end_hex);
	if (flags->point == 0 && end_dec == 0)
		count += ft_printf_pa(flags);
	else if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		count += ft_printf("0x%s", end_hex);
	else if (flags->point > len && flags->point >= flags->width)
		count += ft_printf_pb(flags, len, end_hex);
	else if (flags->width >= len && len > flags->point)
		count += ft_printf_pc(flags, len, end_hex);
	else if (flags->width > flags->point && flags->point >= len)
		count += ft_printf_pd(flags, len, end_hex);
	free(end_hex);
	return (count);
}
