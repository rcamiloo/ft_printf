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
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
	long x;
	x = nb;

	if (x < 0)
	{
		write(1, "-", 1);
		x = x * -1;
	}

	if (x / 10 > 0)
	{
		ft_putnbr(x / 10);
	}
	ft_putchar(x % 10 + '0');
}

int     ft_printf(const char *input, ...)
{
	int d;
	va_list args;
	va_start(args, input);
	while(*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (*input == 'd')
			{
				d = va_arg(args, int);
				ft_putnbr(d);
			}
		}
		else
			ft_putchar(*input);
		input++;
														        }
	va_end(args);
	return (0);
}

int     main(void)
{
	int i;
	i = 0;
	while(i < 3)
	{
		i++;
	}
	ft_printf("bbb%d\n", i);
	printf("bbb%d\n", i);
	return (0);
}
