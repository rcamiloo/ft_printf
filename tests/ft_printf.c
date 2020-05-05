/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuguimo <esuguimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:38:51 by esuguimo          #+#    #+#             */
/*   Updated: 2020/05/05 00:34:49 by esuguimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
			if (*str != '%')//evitando 
			{
				if (*str == '-')// aqui toda flag -, à esquerda
				{
					str++;
					if (*str == '0')// condição não existe, zero fill
					{
						str++;
						width = atoi(str);
						str++;
						if (*str == 'd')
						{
							printf("error: flag '0' is ignored when flag '-' is present.");
							return (-1);
						}
						else if (*str == '%')
						{
							fill = 0;
							printf("%c", '%');
							while (fill < width -1)
							{
								printf("%c", ' ');
								fill++;
							}
							// printf("%c", '%');
						}
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
						else if (*str == '%')
						{
							fill = 0;
							printf("%c", '%');
							while (fill < width -1)
							{
								printf("%c", ' ');
								fill++;
							}
						} 
					}
				}
				else if (*str == '0') 
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
					else if (*str == '%')
					{
						fill = 0;
						while (fill < width -1)
						{
							printf("%d", 0);
							fill++;
						}
						printf("%c", '%');
					}
						
				}
				else if (*str == 'd') // à direita, decimal, sem flags
				{
					// aqui se coloca recursao, dá segfault.
					decimal = va_arg(args, int);
					printf("%d", decimal);
				}
				else if (*str > 0 && (*str != 'd' || *str != 's' 
							|| *str != 'p' || *str != 'c' || *str != 'i'
							|| *str != 'u' || *str != 'x' || *str != 'X')) // à direita width
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
					else if (*str == '%')
					{
						fill = 0;
						while (fill < width -1)
						{
							printf("%c", ' ');
							fill++;
						}
						printf("%c", '%');
					}
				}
			}
			else if (*str == '%')
			{
				printf("%c", '%');
			}
		}	
        else// somente string
        {
          printf("%c", *str);
        }
        str++;
    }
    va_end(args);
    return (0);
}


