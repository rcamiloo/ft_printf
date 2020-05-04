/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuguimo <esuguimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 14:58:19 by esuguimo          #+#    #+#             */
/*   Updated: 2020/05/04 00:59:00 by esuguimo         ###   ########.fr       */
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
        if (*str == '%')// percent 
        {
            str++;
            if (*str == '-')// aqui toda flag -, à esquerda
            {
              str++;
              if (*str == '0')// condição não existe, zero fill
              {
				printf("error: flag '0' is ignored when flag '-' is present.");
				return (-1);
              }
              else if (*str == 'd')// decimal, à esquerda
              {
				  decimal = va_arg(args, int);
                  printf("%d", decimal);
              }
              else if (*str > 0 && (*str != 'd' || *str != 's' || *str != 'p'
			  			|| *str != 'c' || *str != 'i' || *str != 'u'
						||*str != 'x' || *str != 'X')) // à esquerda, width
			  {
                width = atoi(str);
                str++;
                if (*str == 'd') // decimal
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
            }
            else// aqui à direita
			{
				if (*str == '0') // à direita, zero fill
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
				else if (*str == 'd') // à direita, decimal, sem flags
				{
					// aqui se coloca recursao, dá segfault.
				decimal = va_arg(args, int);
				printf("%d", decimal);
				}
				else if (*str > 0 && (*str != 'd' || *str != 's' || *str != 'p'
							|| *str != 'c' || *str != 'i' || *str != 'u'
							||*str != 'x' || *str != 'X')) // à direita width
				{
					width = atoi(str);
					str++;
					if (*str == 'd') // decimal
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
        	}
		}	
        else// somente string
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
    ft_printf("alinhamento à esq, zeros - a original dá warning \n%-04d\n", a);
    //printf("alinhamento à esq, zeros - erro = eri%-06dca\n", a);
    printf("\n");
	printf("\n");
    ft_printf("zeros, alinhamento à direita = e%04d\n", a);
    printf("zeros, alinhamento à direita = e%04d\n", a);
    printf("\n");
	printf("\n");
    ft_printf("sem flags = e%dca\n", a);
    printf("sem flags = e%dca\n", a);
    printf("\n");
	ft_printf("menos flag = %-d\n", a);
    printf("menos flag = %-d\n", a);
    printf("\n");
	printf("\n");
    ft_printf("sem flags nem decimais\n");
    printf("sem flags nem decimais\n");
    printf("\n");
}