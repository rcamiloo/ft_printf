/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuguimo <esuguimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 14:58:19 by esuguimo          #+#    #+#             */
/*   Updated: 2020/05/02 17:48:55 by esuguimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int ft_printf(const char * str, ...)
{
    int decimal;
    int len;
    int width = 0;
    int fill = 0;
    va_list args;
    va_start(args, str);

    while (*str != '\0')
    {
        if (*str == '%')
        {
            str++;
            if (*str == '-')
            {
              str++;
              if (*str == '0')
              {
                str++;
                width = atoi(str);
                str++;
                if (*str == 'd')
                {
                  decimal = va_arg(args, int);
                  len = strlen(str);
                  printf("%d", decimal);
                  while (fill < (width - len))
                  {
                    printf("%d", 0);
                    fill++;
                  }
                  str++;
                }
              }
              else if (*str != 'd' && *str > 0)
              {
                width = atoi(str);
                str++;
                if (*str == 'd')
                {
                  decimal = va_arg(args, int);
                  len = strlen(str);
                  printf("%d", decimal);
                  while (fill < (width - len))
                  {
                    printf("%c", ' ');
                    fill++;
                  }
                  str++;
                }
              }
              else if (*str == 'd')
              {
                  decimal = va_arg(args, int);
                  len = strlen(str);
                  printf("%d", decimal);
                  while (fill < (width - len))
                  {
                    printf("%c", ' ');
                    fill++;
                  }
                  str++;
              }
            }
            else if (*str == '0')
            {
                str++;
                width = atoi(str);
                str++;
                if (*str == 'd')
                {
                  decimal = va_arg(args, int);
                  len = strlen(str);
                  while (fill < (width - len))
                  {
                    printf("%d", 0);
                    fill++;
                  }
                  printf("%d", decimal);
                  str++; 
                }
            }
            else if (*str != 'd' && *str > 0)
            {
              width = atoi(str);
              str++;
              if (*str == 'd')
              {
                decimal = va_arg(args, int);
                len = strlen(str);
                while (fill < (width - len))
                {
                  printf("%c", ' ');
                  fill++;
                }
                printf("%d", decimal);
                str++;
              }
            }
            else if (*str == 'd')
            {
              decimal = va_arg(args, int);
              printf("%d", decimal);
              str++;
            }
        }
        else if (*str)
        {
          printf("%c", *str);
        }
        ++str;
    }
    va_end(args);
    return (0);
}

int main()
{
    int a;
    a = -3;
    ft_printf("eri %-5d\nca", a);
    
}
