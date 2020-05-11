/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilo <camilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:13:22 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/05/09 17:41:20 by camilo           ###   ########.fr       */
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
    flag    flags;

    count = 0;
    
    va_start(args, str);
    while(*str)
    {
        if(*str == '%')
        {
            str++;
            init_flag();
            if(read_flags(str, &flags) >= 0)

                ;

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


typedef struct 
{   
    int zero;
    int minus;
    int precision;
    int width;
    char type;
} flag;

void    init_flag(flag *f)
{
    f->zero = 0;
    f->minus = 0;
    f->precision = -1;
    f->width = 0;
    f->type = '\0';
}

int		ft_isspace(int c)
{
	return (c == '\n' || c == ' ' || c == '\v' || c == '\t'
			|| c == '\r' || c == '\f' || c == '\0');
}

int     ft_isconversion(int c)
{
    return (c == 'c' || c == 's' || c == 'p' || c == 'd'
			|| c == 'i' || c == 'u' || c == 'x' || c == 'X');
}

int     read_flags(char *s, flag *flags)
{
    int len;
    int i;
    

    len =0;
    i = 0;
    while (!(ft_isconversion(s[len])) && !(ft_isspace(s[len])))
        len++;
    if (ft_isspace(s[len]) || !(ft_isconversion(s[len])))
    {
        return (-1);
    }
    flags->type = s[len];
    if (len > 0)
    {
        if ((i <= 1) && s[i] == '0')
        {
            flags->zero = (flags->minus == 0) ? 1 : 0;
            i++;
        }
        if ((i <= 1) && s[i] == '-')
        {
            flags->minus = 1;
            flags->zero = 0;
            i++;
        }
        if ( s[i] >= '0' && s[i] <= '9' && flags->precision == -1)
        {
            while (s[i] >= '0' && s[i] <= '9')
            {
                flags->width = flags->width * 10 + (s[i] - '0');
                i++;
            }
        }
        if (s[i] == '.')
        {
            flags->precision = 0;
            i++;
            while (s[i] >= '0' && s[i] <= '9')
            {
                flags->precision = flags->precision * 10 + (s[i] - '0');
                i++;
            }
        }
    }
    return (i);
}


int    main()
{
    ft_printf("%dmaria %c de baixo %d\n%d\n%d\n%d\n%s hoje não tem nada %s%%\n", 2, 112580, 10, 3, -5000, "joão", "josé");
    return (0);
}


           



