/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpraca-a <kpraca-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:22:27 by kpraca-a          #+#    #+#             */
/*   Updated: 2020/05/02 17:53:01 by kpraca-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	main(void)
{
	int decimal;

	decimal = 48;
	
	printf("Original function\n");
	printf("A b%  d%dc D", decimal, decimal);
	printf("\n");

	printf("Function FT_PRINTF\n");
	ft_printf("A b%  d%dc D", decimal, decimal);
	printf("\n");
}
