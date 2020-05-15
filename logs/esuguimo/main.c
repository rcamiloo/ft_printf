/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuguimo <esuguimo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 21:30:19 by esuguimo          #+#    #+#             */
/*   Updated: 2020/05/12 19:40:58 by esuguimo         ###   ########.fr       */
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
    ft_printf("erica%-5%erica%-5%erica%-5%");
    printf("\n");
    printf("original");
    printf("\n");
    printf("erica%-5%erica%-5%erica%-5%");
    printf("\n");
    printf("ft_printf");
    printf("\n");
    ft_printf("erica%5%erica%5%erica%5%");
    printf("\n");
    printf("original");
    printf("\n");
    printf("erica%5%erica%5%erica%5%");
    printf("\n");
    char strin[] = "12345678";
    printf("\n");
    //ft_printf("%23s", NULL);
    printf("\n");
    //printf("%23s", NULL);
    printf("\n");
    ft_printf("%15.11s", "yolo");
    printf("\n");
    printf("%15.11s", "yolo");
    printf("\n");
    ft_printf("%15.11s", "bombasticlova");
    printf("\n");
    printf("%15.11s", "bombasticlova");
    printf("\n");
    ft_printf("%7.7s%7.7s", "hello", "world");
    printf("\n");
    printf("%7.7s%7.7s", "hello", "world");
    printf("\n");
    ft_printf("%3.7s%7.7s", "hello", "world");
    printf("\n");
    printf("%3.7s%7.7s", "hello", "world");
    printf("\n");
    ft_printf("-%23s", NULL);
    printf("\n");
    printf("-%23s", NULL);
    printf("\n");
    char string25[] = "TESTE 25:%5.4d:";
	ft_printf(string25, -777);
    printf("\n");
    printf(string25, -777);
    printf("\n");
	char string26[] = "TESTE 26:%6.4d:";
	ft_printf(string26, -777);
    printf("\n");
    printf(string26, -777);
    
    printf("\n");
}
