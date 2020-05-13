/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilo <camilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:13:22 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/05/12 22:54:32 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


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

int	    ft_putnbr(int n)
{
	int count;
    
    count = 1;
    if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (10);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
            n = n * -1;
            count++;
		}
		if (n >= 10)
			count = count + ft_putnbr(n / 10);
		ft_putchar((n % 10 + '0'));
	}
    return (count);
}

int     ft_nbrlen(int n)
{
	int count;
    
    count = 1;
    if (n == -2147483648)
		return (10);
	else
	{
		if (n < 0)
		{
            n = n * -1;
            count++;
		}
		if (n >= 10)
			count = count + ft_nbrlen(n / 10);
	}
    return (count);
}

int     printf_d(flag *f, int n)
{
    int count;
    int size_nbr;

    size_nbr = ft_nbrlen(n);
    count = 0;
    if (f->size == 0 || (size_nbr >= f->width && size_nbr >= f->precision))
        return (ft_putnbr(n));
    if (f->precision >= f->width)
    {
        count = f->precision - size_nbr; 
        while (size_nbr < f->precision) 
            return (count);
    }
    return (count);

}

int     print_case(flag *flags, va_list args)
{
    
    if (flags->type == 'd')
        return (printf_d(flags, va_arg(args, int)));
    return (-1);
}

void    init_flag(flag *f)
{
    f->zero = 0;
    f->minus = 0;
    f->precision = -1;
    f->width = 0;
    f->size = 0;
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

int     read_flags(const char *s, flag *flags)
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
    flags->size = i;
    return (i);
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
            init_flag(&flags);
            if(read_flags(str, &flags) >= 0)
            {   
                str = str + read_flags(str, &flags);
                count = count + print_case(&flags, args);
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
    ft_printf("teste 1: %d asdf\nNova linha", -10);
    return (0);
}


           



