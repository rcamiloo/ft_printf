/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuguimo <esuguimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 21:30:19 by esuguimo          #+#    #+#             */
/*   Updated: 2020/05/05 00:28:29 by esuguimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_printf(const char * str, ...);
int main(void)
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
    
    printf("Original function\n");
	printf("A b%  d%dc D", a, a);
	printf("\n");

	printf("Function FT_PRINTF\n");
	ft_printf("A b%  d%dc D", a, a);
	printf("\n");
    printf("ft_printf");
    printf("\n");
    ft_printf("erica%-5%erica%-5%erica%-5%");
    printf("\n");
    printf("original");
    printf("\n");
    printf("erica%-5%erica%-5%erica%-5%");
    printf("\n");
}
