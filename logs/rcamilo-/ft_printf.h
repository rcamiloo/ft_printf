/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilo <camilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:23:18 by camilo            #+#    #+#             */
/*   Updated: 2020/05/12 22:51:29 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

typedef struct 
{   
    int zero;
    int minus;
    int precision;
    int width;
    int size;
    char type;
} flag;

void	ft_putchar(char c);
void	ft_putstr(char *s);
int	    ft_putnbr(int n);
int	    ft_nbrlen(int n);
int     printf_d(flag *f, int n);
int     print_case(flag *flags, va_list args);
void    init_flag(flag *f);
int		ft_isspace(int c);
int     ft_isconversion(int c);
int     read_flags(const char *s, flag *flags);
int     ft_printf(const char *str, ...);

#endif