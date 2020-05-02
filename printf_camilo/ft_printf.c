/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilo <camilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:13:22 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/05/02 19:45:15 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (s != NULL)
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = n * -1;
		}
		if (n >= 10)
			ft_putnbr(n / 10);
		ft_putchar((n % 10 + '0'));
	}
}


int     ft_printf(const char *str, ...)
{
    va_list args;
    size_t  count;

    count = 0;
    va_start(args, str);
    while(*str)
    {
        if(*str == '%')
        {
            str++;
            if (*str == 'd')
            {
                ft_putnbr(va_arg(args, int));
            }
            else if (*str == 's')
            {
                 ft_putstr(va_arg(args, char *));
            }
            
        }
        else
        {
            ft_putchar(*str);
        }
       str++;
    }
    va_end(args);
    return (0);
}

int    main()
{
    ft_printf("%dmaria %c de baixo %d\n%d\n%d\n%d\n%s hoje não tem nada %s%%\n", 2, 112580, 10, 3, -5000, "joão", "josé");
    return (0);
}


           



