/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilo <camilo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:41:06 by camilo            #+#    #+#             */
/*   Updated: 2020/05/09 17:12:26 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


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

int     read_flags(char *s)
{
    int len;
    int i;
    flag flags;
    

    len =0;
    i = 0;
    init_flag(&flags);
    while (!(ft_isconversion(s[len])) && !(ft_isspace(s[len])))
        len++;
    if (ft_isspace(s[len]) || !(ft_isconversion(s[len])))
    {
        return (-1);
    }
    flags.type = s[len];
    if (len > 0)
    {
        if ((i <= 1) && s[i] == '0')
        {
            flags.zero = (flags.minus == 0) ? 1 : 0;
            i++;
        }
        if ((i <= 1) && s[i] == '-')
        {
            flags.minus = 1;
            flags.zero = 0;
            i++;
        }
        if ( s[i] >= '0' && s[i] <= '9' && flags.precision == -1)
        {
            while (s[i] >= '0' && s[i] <= '9')
            {
                flags.width = flags.width * 10 + (s[i] - '0');
                i++;
            }
        }
        if (s[i] == '.')
        {   
            flags.precision = 0;
            i++;
            while (s[i] >= '0' && s[i] <= '9')
            {
                flags.precision = flags.precision * 10 + (s[i] - '0');
                i++;
            }
        }
    }
    printf("type: %c\n", flags.type);
    printf("minus: %d\n", flags.minus);
    printf("zero: %d\n", flags.zero);
    printf("width: %d\n", flags.width);
    printf("precision: %d\n\n", flags.precision);

    return (i);
}



int main()
{
    printf("d\n");
    read_flags("d");
    printf("0-5.02d\n");
    read_flags("0-5.02d");
    printf("-05.03z\n\n");
    read_flags("-05.03z");
    printf("-04.d\n");
    read_flags("-04.d");
    printf("-05.x02d\n");
    read_flags("-05.x02d");
	printf("%-05.z02d", 2);
    return (0);
}
