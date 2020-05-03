/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuguimo <esuguimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 14:58:19 by esuguimo          #+#    #+#             */
/*   Updated: 2020/05/03 15:28:06 by esuguimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

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
            if (*str == '-') // aqui toda flag -, à esquerda
            {
              str++;
              if (*str == '0') // condição não existe, zero fill
              {
                str++;
                width = atoi(str);
                str++;
                if (*str == 'd')
                {
					len = strlen(str);
                  decimal = va_arg(args, int);
                  ft_printf("%d", decimal);
                  while (fill < (width - len) +1)
                  {
                    printf("%d", 0);
                    fill++;
                  }
                }
              }
              else if (*str != 'd' && *str > 0) // à esquerda, width
              {
                width = atoi(str);
                str++;
                if (*str == 'd')
                {
                  decimal = va_arg(args, int);
                  printf("%d", decimal);
                  len = strlen(str);
                  while (fill < (width - len) +1)
                  {
                    printf("%c", ' ');
                    fill++;
                  }
                }
              }
              else if (*str == 'd') // decimal, à esquerda
              {
                  decimal = va_arg(args, int);
                  printf("%d", decimal);
              }
            }
            else if (*str == '0') // sem alinhamento, zero fill
            {
                str++;
                width = atoi(str);
                str++;
                if (*str == 'd')
                {
                  len = strlen(str);
				  decimal = va_arg(args, int);
				  if (decimal < 0)
				  {
					  printf("%c", '-');
					  decimal = decimal * -1;
				  }
                  while (fill < (width - len) -1)
                  {
                    printf("%d", 0);
                    fill++;
                  }
                  printf("%d", decimal);
                }
            }
			else if (*str != 'd' && *str > 0) // sem alinhamento, width
              {
                width = atoi(str);
                str++;
                if (*str == 'd')
                {
					len = strlen(str);
                  while (fill < (width - len) +1)
                  {
                    printf("%c", ' ');
                    fill++;
                  }
				  decimal = va_arg(args, int);
                  printf("%d", decimal);
                }
              }
            else if (*str == 'd') // decimal, sem flags
            {
                // aqui se coloca recursao, dá segfault.
              decimal = va_arg(args, int);
              printf("%d", decimal);
            }
        }
        else if (*str) // somente string
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
    a = -13;
    printf("\n");
    ft_printf("alinhamento à esq, espaço vazio= eri%-4dca\n", a);
    printf("alinhamento à esq, espaço vazio= eri%-4dca\n", a);
    printf("\n");
    ft_printf("alinhamento à direita, espaço vazio = eri%4dca\n", a);
    printf("alinhamento à direita, espaço vazio = eri%4dca\n", a);
    printf("\n");
	printf("\n");
    ft_printf("alinhamento à esq, zeros - a original dá warning = eri%-04dca\n", a);
    //printf("alinhamento à esq, zeros - erro = eri%-06dca\n", a);
    printf("\n");
    ft_printf("zeros, alinhamento à direita = e%04d\n", a);
    printf("zeros, alinhamento à direita = e%04d\n", a);
    printf("\n");
	printf("\n");
    ft_printf("sem flags = e%dca\n", a);
    printf("sem flags = e%dca\n", a);
    printf("\n");
	ft_printf("menos flag = e%-dca\n", a);
    printf("menos flag = e%-dca\n", a);
    printf("\n");
	printf("\n");
    ft_printf("sem flags nem decimais\n");
    printf("sem flags nem decimais\n");
    printf("\n");
}