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
	int return_printf;
	int return_ft_printf;

	decimal = 42;
	
	printf("------------------------------------------\n");
	printf("Hello % World\n");
	printf("------------------------------------------\n");


	printf("Hello % World| PRINTF\n");
	ft_printf("Hello % World| FT_PRINTF\n\n");
	

	printf("------------------------------------------\n");
	printf("Conversion: d | variable: int decimal = %d\n", decimal);
	printf("------------------------------------------\n");
	
	return_printf		=    printf("A b%dc D| PRINTF\n", decimal);
	return_ft_printf	= ft_printf("A b%dc D| PRINTF\n", decimal);
	printf("\n");
	
	printf("%d| PRINTF - RETURN ABOVE\n", return_printf);
	printf("%d| FT_PRINTF - RETURN ABOVE\n\n", return_ft_printf);
	
	printf("%01d| PRINTF    - 01d\n", decimal);
	ft_printf("%01d| FT_PRINTF - 01d\n\n", decimal);

	return_printf		=    printf("%05d| PRINTF - 05d\n", decimal);
	return_ft_printf	= ft_printf("%05d| PRINTF - 05d\n", decimal);
	printf("\n");
	printf("%d| PRINTF - RETURN ABOVE\n", return_printf);
	printf("%d| FT_PRINTF - RETURN ABOVE\n\n", return_ft_printf);

	printf("%1d| PRINTF    - 01d\n", decimal);
	ft_printf("%1d| FT_PRINTF - 01d\n\n", decimal);

	printf("%5d| PRINTF    - 5d\n", decimal);
	ft_printf("%5d| FT_PRINTF - 5d\n\n", decimal);

	printf("%1| PRINTF    - 1\n", decimal);
	ft_printf("%1| FT_PRINTF - 1\n\n", decimal);
	
	printf("----Flag '-' -------------------------------------\n");

	return_printf		=    printf("%-d| PRINTF - -d\n", decimal);
	return_ft_printf	= ft_printf("%-d| PRINTF - -d\n", decimal);

	printf("\n");
	printf("%d| PRINTF - RETURN ABOVE\n", return_printf);
	printf("%d| FT_PRINTF - RETURN ABOVE\n\n", return_ft_printf);

	return_printf 		=    printf("%-5d| PRINTF - -5d\n", decimal);
	return_ft_printf 	= ft_printf("%-5d| PRINTF - -5d\n", decimal);

	printf("\n");
	printf("%d| PRINTF - RETURN ABOVE\n", return_printf);
	printf("%d| FT_PRINTF - RETURN ABOVE\n\n", return_ft_printf);



	printf("----Flag '*' -------------------------------------\n");

   	 int w = 7;
    
	printf("%*d|    printf só *\n", w, decimal);
     ft_printf("%*d| ft_printf so *\n\n", w, decimal);

	printf("%0*d|    printf 0*\n", w, decimal);
     ft_printf("%0*d| ft_printf 0*\n\n", w, decimal);

        printf("%*0d|    printf *0\n", w, decimal);
     ft_printf("%*0d| ft_printf *0\n\n", w, decimal);
	
	printf("%-*d|    printf -*\n", w, decimal);
     ft_printf("%-*d| ft_printf -*\n\n", w, decimal);

    	printf("%7*d|    printf 7*\n", w, decimal);
     ft_printf("%7*d| ft_printf 7*\n\n", w, decimal);

       	printf("%07*d|    printf 07*\n", w, decimal);    
     ft_printf("%07*d| ft_printf 07*\n\n", w, decimal);   

	printf("\n");

}
