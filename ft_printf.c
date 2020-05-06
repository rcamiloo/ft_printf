/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvidigal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 16:28:49 by bvidigal          #+#    #+#             */
/*   Updated: 2020/01/01 16:28:35 by bvidigal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int     ft_printf(const char *input, ...)
{
	int d;
	int valnum;
	unsigned int x;
	char *s;
	unsigned long int p;
	//valnum tem que ser o atoi do input

	va_list args;
	va_start(args, input);
	while(*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (*input == '%')
				ft_putchar(*input);
			if (*input == '+')
			{
				input++;
				if (*input == 'd' || *input == 'i')
				{
					input++;
					d = va_arg(args, int);
					if (d >= 0)
						ft_putchar('+');
					ft_putnbr(d);
				}
				ft_putchar(*input);
			}
			if (*input == '-')
			{
				input++;
				valnum = ft_atoi(input);
				while (ft_isnum(*input))
					input++;
				if (*input == 'd' || *input == 'i')
				{
					input++;
					d = va_arg(args, int);
					ft_putnbr(d);
				}
				if (d < 0)
					valnum--;
				if (*input == 'c')
					ft_putchar((char)va_arg(args, int));
				if(*input == 's')
				{
					s = va_arg(args, char *);
					ft_printf(s);
				}
				while (valnum > 1)
				{
					ft_putchar(' ');
					valnum--;
				}
				ft_putchar(*input);

			}
			if (*input == '0')
			{
				input++;
				valnum = ft_atoi(input);
				while(ft_isnum(*input))
					input++;
				while (valnum > 1)
				{
					valnum--;
					ft_putchar('0');
				}

			}
			if (*input == 'd' || *input == 'i')
			{
				ft_putnbr(va_arg(args, int));
			}
			if (*input == 'c')
			{
				ft_putchar((char)va_arg(args, int));
			}
			if (*input == 's')
			{
				s = va_arg(args, char *);
				ft_printf(s);
			}
			if (*input == 'x')
			{
				x = va_arg(args, unsigned int);
				ft_puthex(x);
			}
			if (*input == 'X')
			{
				x = va_arg(args, unsigned int);
				ft_puthex(x);
			}
			if (*input == 'p')
			{
				p = va_arg(args, unsigned long int);
				ft_printf("0x");
				ft_puthex(p);
			}
			if (*input == 'u')
			{
				x = va_arg(args, unsigned int);
				ft_putnbr(x);
			}
		}
		else
			ft_putchar(*input);
		input++;
	}
	va_end(args);
	return (0);
}
