/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuguimo <esuguimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:38:51 by esuguimo          #+#    #+#             */
/*   Updated: 2020/05/09 18:17:17 by esuguimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
size_t	ft_nbrlen(int nbr)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < len)
		len += 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

int ft_printf(const char *format, ...)
{
    char *str;
	int valor;
    int len;
	int i;
	int wlen;
    int width;
    int fill;
    va_list args;
    va_start(args, format);
	i = 0;
	

    while (*format != '\0')
    {
        if (*format == '%')// percent 
        {
            format++;
			while (*format == ' ')
			{
				format++;
			}
			if (*format != '%')//evitando 
			{
				if (*format == '-')// aqui toda flag -, à esquerda
				{
					format++;
					if (*format == '0')// condição existe somente para %
					{
						format++;
						if (*format > 0 && (*format != 'd' || *format != 's' || *format != 'p'
							|| *format != 'c' || *format != 'i' || *format != 'u'
							||*format != 'x' || *format != 'X')) // à esquerda, width
						{
							// width = atoi(format);
							// format++;
							width = 0;
							while (format[i] >= '0' && format[i] <= '9')
							{
								width = width * 10 + (format[i] - '0');
								i++;
							}
							format++;
							wlen = ft_nbrlen(width);
							i = 1;
							while (i < wlen)
							{
								format++;
								i++;
							}
							if (*format == 'd' || *format == 'i') // valor
							{
								fill = 0;
								valor = va_arg(args, int);
								len = ft_nbrlen(valor);
								printf("%d", valor);
								while (fill < (width -len))
								{
									printf("%c", ' ');
									fill++;
								}
							}
							else if (*format == '%')
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
					else if (*format == 'c')// caracter, à esquerda
					{
						valor = va_arg(args, int);
						printf("%c", valor);
					}
					else if (*format == 's')// caracter, à esquerda
					{
						str = va_arg(args, char *);
						printf("%s", str);
					}
					else if (*format == 'p')
					{
						str = va_arg(args, char *);
						printf("%p", &str[0]);
					}
					else if (*format == 'd' || *format == 'i')// decimal, à esquerda
					{
						valor = va_arg(args, int);
						printf("%d", valor);
					}
					else if (*format > 0 && (*format != 'd' || *format != 's' || *format != 'p'
								|| *format != 'c' || *format != 'i' || *format != 'u'
								||*format != 'x' || *format != 'X')) // à esquerda, width
					{
						width = 0;
						while (format[i] >= '0' && format[i] <= '9')
						{
							width = width * 10 + (format[i] - '0');
							i++;
						}
						format++;
						wlen = ft_nbrlen(width);
						i = 1;
						while (i < wlen)
						{
							format++;
							i++;
						}
						if (*format == 'c') // valor
						{
							fill = 0;
							valor = va_arg(args, int);
							len = 1;
							printf("%c", valor);
							while (fill < (width - len))
							{
								printf("%c", ' ');
								fill++;
							}
						}
						else if (*format == 's') // valor
						{
							fill = 0;
							str = va_arg(args, char *);
							printf("%s", str);
							len = strlen(str);
							while (fill < (width - len))
							{
								printf("%c", ' ');
								fill++;
							}
						}
						else if (*format == 'p')
						{
							fill = 0;
							str = va_arg(args, char *);
							printf("%p", &str[0]);
							len = 14;
							while (fill < (width -len))
							{
								printf("%c", ' ');
								fill++;
							}
						}
						else if (*format == 'd' || *format == 'i') // valor
						{
							fill = 0;
							valor = va_arg(args, int);
							len = ft_nbrlen(valor);
							printf("%d", valor);
							while (fill < (width -len))
							{
								printf("%c", ' ');
								fill++;
							}
						}
						else if (*format == '%')
						{
							fill = 0;
							printf("%c", '%');
							while (fill < width -1)
							{
								printf("%c", '.');
								fill++;
							}
						}
					}
				}
				else if (*format == '0') 
				{
					format++;
					width = 0;
					while (format[i] >= '0' && format[i] <= '9')
					{
						width = width * 10 + (format[i] - '0');
                		i++;
					}
					format++;
					wlen = ft_nbrlen(width);
					i = 1;
					while (i < wlen)
					{
						format++;
						i++;
					}
					if (*format == 'd' || *format == 'i')
					{
						fill = 0;
						valor = va_arg(args, int);
						len = ft_nbrlen(valor);
						if (valor < 0)
						{
							printf("%c", '-');
							valor = valor * -1;
						}
						while (fill < (width - len))
						{
							printf("%d", 0);
							fill++;
						}
						printf("%d", valor);
					}
					else if (*format == '%')
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
				else if (*format == 'c') // à direita, caracter, sem flags
				{
					// aqui se coloca recursao, dá segfault.
					valor = va_arg(args, int);
					printf("%c", valor);
				}
				else if (*format == 's') // à direita, caracter, sem flags
				{
					// aqui se coloca recursao, dá segfault.
					str = va_arg(args, char *);
					printf("%s", str);
				}
				else if (*format == 'p') // à direita, valor, sem flags
				{
					// aqui se coloca recursao, dá segfault.
					str = va_arg(args, char *);
					printf("%p", &str[0]);
				}
				else if (*format == 'd' || *format == 'i') // à direita, valor, sem flags
				{
					// aqui se coloca recursao, dá segfault.
					valor = va_arg(args, int);
					printf("%d", valor);
				}
				else if (*format > 0 && (*format != 'd' || *format != 's' 
							|| *format != 'p' || *format != 'c' || *format != 'i'
							|| *format != 'u' || *format != 'x' || *format != 'X')) // à direita width
				{
					width = 0;
					while (format[i] >= '0' && format[i] <= '9')
					{
						width = width * 10 + (format[i] - '0');
                		i++;
					}
					format++;
					wlen = ft_nbrlen(width);
					i = 1;
					while (i < wlen)
					{
						format++;
						i++;
					}
					if (*format == 'c') // valor corrigir que nao esta bem
					{
						fill = 0;
						len = 1;
						while (fill < (width - len))
						{
							fill++;
							printf("%c", ' ');
						}
						valor = va_arg(args, int);
						printf("%c", valor);
					}
					else if (*format == 's') // valor corrigir que nao esta bem
					{
						fill = 0;
						str = va_arg(args, char *);
						len = strlen(str);
						while (fill < (width - len))
						{
							fill++;
							printf("%c", ' ');
						}
						printf("%s", str);
					}
					else if (*format == 'p')
					{
						fill = 0;
						str = va_arg(args, char *);
						len = 14;
						while (fill < (width-len))
						{
							fill++;
							printf("%c", ' ');
						}
						printf("%p", &str[0]);
					}
					else if (*format == 'd' || *format == 'i') // valor corrigir que nao esta bem
					{
						fill = 0;
						valor = va_arg(args, int);
						len = ft_nbrlen(valor);
						while (fill < (width - len))
						{
							fill++;
							printf("%c", ' ');
						}
						printf("%d", valor);
					}
					else if (*format == '%')
					{
						fill = 0;
						while (fill < width -1)
						{
							printf("%c", ' ');
							fill++;
						}
						//printf("%d", width);
						printf("%c", '%');
					}
				}
			}
			else if (*format == '%')
			{
				printf("%c", '%');
			}
		}	
        else// somente string
        {
          printf("%c", *format);
        }
        format++;
    }
    va_end(args);
    return (0);
}


