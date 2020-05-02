/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuguimo <esuguimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 14:58:19 by esuguimo          #+#    #+#             */
/*   Updated: 2020/05/02 14:58:36 by esuguimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

int ft_printf(const char * str, ...)
{
    int j = 0;
    int i;
    int y = 0;
    int len;
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
                y = atoi(str);
                str++;
                if (*str == 'd')
                {
                  i = va_arg(args, int);
                  len = strlen(str);
                  printf("%d", i);
                  while (j < (y - len))
                  {
                    printf("%d", 0);
                    j++;
                  }
                  str++;
                }
              }
              else if (*str != 'd' && *str > 0)
              {
                y = atoi(str);
                str++;
                if (*str == 'd')
                {
                  i = va_arg(args, int);
                  len = strlen(str);
                  printf("%d", i);
                  while (j < (y - len))
                  {
                    printf("%d", ' ');
                    j++;
                  }
                  str++;
                }
              }
              else if (*str == 'd')
              {
                  i = va_arg(args, int);
                  len = strlen(str);
                  printf("%d", i);
                  while (j < (y - len))
                  {
                    printf("%d", ' ');
                    j++;
                  }
                  str++;
              }
            }
            else if (*str == '0')
            {
                str++;
                y = atoi(str);
                str++;
                if (*str == 'd')
                {
                  i = va_arg(args, int);
                  len = strlen(str);
                  while (j < (y - len))
                  {
                    printf("%d", 0);
                    j++;
                  }
                  printf("%d", i);
                  str++; 
                }
            }
            else if (*str != 'd' && *str > 0)
            {
              y = atoi(str);
              str++;
              if (*str == 'd')
              {
                i = va_arg(args, int);
                len = strlen(str);
                while (j < (y - len))
                {
                  printf("%d", '\0');
                  j++;
                }
                printf("%d", i);
                str++;
              }
            }
            else if (*str == 'd')
            {
              i = va_arg(args, int);
              printf("%d", i);
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
    ft_printf("erica %d\n", a);
    
}
