/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:10:27 by dmoreira          #+#    #+#             */
/*   Updated: 2020/05/15 00:42:48 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include <stdio.h>

int main(void)
{
	int letras;

	char string[] = ">>>>>>>>>>>>>>>>>>>>>>>>>PRINT INTEGER<<<<<<<<<<<<<<<<<<<<<<<\n\n";
	ft_printf(string);
	char string1[] = "TESTE 1:%d:";
	letras = ft_printf(string1, 123);
	printf("\nTESTE R:123:\nQuantidade de letras retorna: %d\nQuantidade de letras correta: 12\n\n", letras);

}
