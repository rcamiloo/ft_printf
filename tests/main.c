/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuguimo <esuguimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 21:30:19 by esuguimo          #+#    #+#             */
/*   Updated: 2020/05/09 18:21:38 by esuguimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_printf(const char * str, ...);
int main(void)
{
    int a;
    a = -13;
    int letras;
    printf("\n");
    ft_printf("alinhamento à esq, espaço vazio= eri%-8dca\n", a);
    printf("alinhamento à esq, espaço vazio= eri%-8dca\n", a);
    printf("\n");
    ft_printf("alinhamento à direita, espaço vazio = eri%8dca\n", a);
    printf("alinhamento à direita, espaço vazio = eri%8dca\n", a);
    printf("\n");
	printf("\n");
    ft_printf("alinhamento à esq, zeros - a original dá warning \n%-5c\n", 'a');
    printf("alinhamento à esq, zeros - erro = \n%-5c\n", 'a');
    printf("\n");
	printf("\n");
    ft_printf("zeros, alinhamento à direita = e%05d\n", a);
    printf("zeros, alinhamento à direita = e%05d\n", a);
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
    ft_printf("erica%-15%erica%-5%erica%-5%");
    printf("\n");
    printf("original");
    printf("\n");
    printf("erica%-15%erica%-5%erica%-5%");
    printf("\n");
    printf("ft_printf");
    printf("\n");
    ft_printf("erica%15%erica%5%erica%5%");
    printf("\n");
    printf("original");
    printf("\n");
    printf("erica%15%erica%5%erica%5%");
    printf("\n");
    char strin[] = "12345678";
    printf("\n");
    ft_printf("%100d", 123);
    printf("\n");
    printf("%100d", 123);
    ft_printf("\naqui-TESTE 02:%-011s:", strin);
    ft_printf("\naqui-TESTE 02:%-09s:", strin);
	//printf("\naqui-TESTE 02:%-09s:", strin);
    printf("\n");
	char string22[] = "\nTESTE 22:%-09d :";
	letras = ft_printf("\nTESTE 22:%-011d :", 777);
    letras = ft_printf("\nTESTE 22:%-09d :", 777);
    //printf(string22, 777);
    printf("\nQuantidade de letras retorna: %d\nQuantidade de letras correta: 14\n\n", letras);
}
