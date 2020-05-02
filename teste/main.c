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

void	*ft_memset(void *dest, int c, size_t len)
{
	if (len > 0)
	{
		while (len--)
		{
			*(unsigned char *)(dest + len) = (unsigned char)(c);
		}
	}
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	ft_puthex(__uint64_t nb)
{
	char hex[16];
	int  tmp;
	int  i;

	ft_bzero(hex, 16);
	i = 0;
	while (nb)
	{
		tmp = nb % 16;
		hex[i] = (tmp + (tmp >= 10 ? ('a' - 10) : '0'));
		nb /= 16;
		i++;
	}
	while (i >= 1)
	{
	i--;
	ft_putchar(hex[i]);
	}
}

int     ft_printf(const char *input, ...)
{
	int d;
	char c;
	const char *s;
	unsigned int x;
	va_list args;
	va_start(args, input);
	while(*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (*input == '+')
			{
				input++;
				if (*input == 'd')
				{
					input++;
					d = va_arg(args, int);
					if ( d >= 0)
						ft_putchar('+');
					ft_putnbr(d);
				}
				ft_putchar(*input);
			}
			if (*input == 'd')
			{
				d = va_arg(args, int);
				ft_putnbr(d);
			}	
			if (*input == 'c')
			{
				c = va_arg(args, int);
				ft_putchar(c);
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
	int n = -1;
	char c;
	char *s ="hello world";
	int hex =0xfafa;
	
	c = 'k';

	i = 0;
	while(i < 3)
	{
		i++;
	}
	ft_printf("\n");
	ft_printf("======int=d====\n");
	ft_printf("\n");
	ft_printf("%d%d%d			<ft_printf\n", i, i, i);
	printf("%d%d%d			<printf\n", i, i , i);
	ft_printf("\n");
	ft_printf("======char=c====\n");
	ft_printf("\n");
	ft_printf("this is a char -> %c	<ft_printf\n", c);
	printf("this is a char -> %c	<printf\n", c);
	ft_printf("\n");
	ft_printf("======str=s=====\n");
	ft_printf("\n");
	ft_printf("%s		<ft_printf\n", s);
	printf("%s		<printf\n", s);
	ft_printf("\n");
	ft_printf("======hex=x====\n");
	ft_printf("\n");
	ft_printf("x = %x d = %d	<ft_printf\n", hex, hex);
	printf("x = %x d = %d	<printf\n", hex, hex);
	ft_printf("\n");
	ft_printf("<<<<<<<< FLAGS >>>>>>>>\n");
	ft_printf("\n");
	ft_printf("======= + =======\n");
	ft_printf("flag + = %+d positivo	<ft_printf\n", i);
	printf("flag + = %+d positivo	<printf\n", i);
	ft_printf("\n");
	ft_printf("flag + = %+d negativo	<ft_printf\n", n);
	ft_printf("flag + = %+d negativo	<printf\n", n);
	ft_printf("\n");
	ft_printf("flag + = %+d zero	<ft_printf\n", 0);
	printf("flag + = %+d zero	<printf\n", 0);
	return (0);
}
