/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esquema.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuguimo <esuguimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 19:28:58 by esuguimo          #+#    #+#             */
/*   Updated: 2020/05/02 20:01:42 by esuguimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

int ft_printf(const char * str, ...)
{
    va_list args;
    va_start(args, str);
    while (*str != '\0')
    {
        if (*str == '%')
        {
            // aqui dentro puxar as funções???
        }
        else
            printf("%c", *str);
        str++;
    }
    va_end(args);
    return (0);
}

int main()
{
    int a;
    a = -3;
    //ft_printf("alinhamento à esq, espaço vazio= eri%-6d\nca\n", a);
    //ft_printf("espaço, alinhamento à direita = eri%6d\nca\n", a);
    //ft_printf("alinhamento à esq, zeros = %-06d\n\n", a);
    //ft_printf("zeros, alinhamento à direita = %06d\n\n", a);
    //ft_printf("sem flags = %d\n\n", a);
    ft_printf("erica\n");
}