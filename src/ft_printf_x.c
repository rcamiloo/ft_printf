/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:38:47 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/07/23 23:01:43 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	digitcounter(unsigned long int n)
{
	if (!(n / 16))
		return (1);
	else
		return (digitcounter(n / 16) + 1);
}

char		*ft_itoa_base(unsigned long int n, char type)
{
	char	*hexnumber;
	int		len;
	char	*base;

	base = type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	len = digitcounter(n);
	if (!(hexnumber = malloc((len + 1) * sizeof(*hexnumber))))
		return (NULL);
	hexnumber[len] = '\0';
	while (len--)
	{
		hexnumber[len] = base[n % 16];
		n /= 16;
	}
	return (hexnumber);
}

static int	ft_printf_xa(t_flags *flags, int len, char *number)
{
	int count;

	count = 0;
	if (flags->minus == 0 && flags->zero == 1 && flags->point == -1)
		count += ft_putflags(flags->width - len, '0');
	else if (flags->minus == 0 && flags->zero == 1)
		count += ft_putflags(flags->width - len, ' ');
	else if (flags->minus == 0 && flags->zero == 0)
		count += ft_putflags(flags->width - len, ' ');
	count += ft_printf(number);
	if (flags->minus == 1)
		count += ft_putflags(flags->width - len, ' ');
	return (count);
}

static int	ft_printf_xb(t_flags *flags, int len, char *number)
{
	int count;

	count = 0;
	if (flags->minus == 0)
		count += ft_putflags(flags->width - flags->point, ' ');
	count += ft_putflags(flags->point - len, '0');
	count += ft_printf(number);
	if (flags->minus == 1)
		count += ft_putflags(flags->width - flags->point, ' ');
	return (count);
}

int			ft_printf_x(t_flags *flags, va_list args)
{
	int		count;
	int		dec;
	int		len;
	char	*number;

	ft_printf_star(flags, args);
	dec = va_arg(args, int);
	number = ft_itoa_base((unsigned int)dec, flags->type);
	count = 0;
	len = ft_strlen(number);
	if (flags->point == 0 && dec == 0)
		count += ft_putflags(flags->width, ' ');
	else if (flags->len == 0 || (len >= flags->width && len >= flags->point))
		count += ft_printf(number);
	else if (flags->point > len && flags->point >= flags->width)
		count += ft_putflags(flags->point - len, '0') + ft_printf(number);
	else if (flags->width >= len && len > flags->point)
		count += ft_printf_xa(flags, len, number);
	else if (flags->width > flags->point && flags->point >= len)
		count += ft_printf_xb(flags, len, number);
	free(number);
	return (count);
}
