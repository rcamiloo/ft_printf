/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpraca-a <kpraca-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:55:08 by kpraca-a          #+#    #+#             */
/*   Updated: 2020/05/02 17:28:38 by kpraca-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h> //depois excluir


int	ft_printf_flag_number_value(const char *fmt, char end)// Trata o número da flag
{
	int num;
	num = 0;
	
	while(*fmt != end)
	{	
		if (*fmt >= '0' && *fmt <= '9') //Descobir tamanho passado
		{
			while (*fmt >= '0' && *fmt <= '9') //converte para numero
			{
				if (num == 0) //executa primeiro
					num = ft_atoi(fmt);
				fmt++;
			}
			return(num); //Descobri que tenho flag 0 e fla 5
		}
		fmt++;
	}
	return (num);
}

int	ft_printf_flag_characters(char fmt)//Trata os caracteres da flag
{
	int flag;
	char flags[8] = {'-', '0', '.', '*', '#', ' ', '+', '\0'}; // NÃO VAI PASSAR NA NORMINHA FÁCIL DE CORRIGIR MAS NÃO VOU PERDER MAIS TEMPO COM IÇÇÇÇÇÇÇÇO
	int i;
	int expoente;
	int resultado;

	flag = 0;
	i = 0;
	resultado = 1;
	while (flags[i] != '\0')
	{
		if (flags[i] == fmt)
		{
			expoente = 0;
			while (expoente < i)
			{
				resultado *= 10;
				expoente++;
			}
			flag += resultado;
		}
		i++;
	}
	return (flag);
}

int	ft_printf_d(va_list args, const char *fmt_beg, char *fmt_end)//Conversão de d é passado % ... d três pontos são as flags
{
	int size;
	int argumento;
	int num;
	int flag;

	size = 0;
	argumento = va_arg(args, int);
////////////////////////////////////////////////////////////////////////
//excluir flags = ['-','0','.','*','#',' ','+','\0']
	flag = 0;	
	num = ft_printf_flag_number_value(fmt_beg, *fmt_end) - ft_strlen(ft_itoa(argumento));
	while (fmt_beg++ != fmt_end)
		flag += ft_printf_flag_characters(*fmt_beg);
	if (flag == 1)//Flag '-'
		size += ft_writenbr(argumento) + ft_writestr(ft_writemalloc(num, ' '));
	else if (flag == 10)
		size += ft_writestr(ft_writemalloc(num, '0')) + ft_writenbr(argumento);
	else	
		size += ft_writestr(ft_writemalloc(num, ' ')) + ft_writenbr(argumento);

	
//	if (fmt_beg++ != fmt_end)
//	{
//		num = ft_printf_flag_number_value(fmt_beg, *fmt_end) - ft_strlen(ft_itoa(argumento));
//		if (*fmt_beg == '-') // Flag '-' ' ' no final
//		{
//			size += ft_writenbr(argumento);
//			while (num > 0 && num--)
//				size += ft_writechar(' ');
//			return (size);
//		}
//		else if (*fmt_beg == '0') //Flag '0' no começo
//			while (num > 0 && num--)
//				size += ft_writechar('0');
//		else
//			while (num > 0 && num--) // ' ' no começo
//				size += ft_writechar(' ');
//		size += ft_writenbr(argumento);
//	}
	return (size);
}

int	ft_printf_conversion(va_list args, const char *fmt)// Identifica tipo de conversão
{
	int	size;
	char	*fmt_c;

	size = 0;
	fmt_c = (char*)fmt;
	while(fmt_c++)
	{
		if (*fmt_c == 'd') // Conversão d
			return(size += ft_printf_d(args, fmt, fmt_c));//Passo % ... d
		else   
			if ((*fmt_c >= 'a' && *fmt_c <= 'z') || (*fmt_c >= 'A' && *fmt_c <= 'Z'))
				return (0);
	}
	return (size);
}

int	ft_printf(const char *fmt, ...) // Imprime não é conversão e chama função que trata a conversão
{
	va_list	args;
	int	size;
	int	ret_conv;

	size = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			ret_conv = ft_printf_conversion(args, fmt);
			if (ret_conv)
				while(*(fmt++ +1) != 'd' && *fmt != 'c');
			else
				ft_writechar('%');
			size += ret_conv;
		}
		else
			size += ft_writechar(*fmt);
		fmt++;
	}
	va_end(args);
	return (size);
}
