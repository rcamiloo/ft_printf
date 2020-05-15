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

int	ft_printf_flag_characters(const char *fmt_beg, char fmt_end)//Trata os caracteres da flag
{
	int flag;
	char flags[8] = {'-', '0', '.', '*', '#', ' ', '+', '\0'};//NÃO VAI PASSAR NA NORMINHA
	int i;
	int expoente;
	int resultado;

	flag = 0;
	while (*(fmt_beg++) != fmt_end)
	{
		resultado = 1;
		i = -1;
		while (flags[++i] != '\0')
		{
			if (flags[i] == *fmt_beg)
			{
				expoente = 0;
				while (expoente++ < i)
					resultado *= 10;
			ft_writestr("XxX");
				if (flag == 1000 && resultado > 1 && resultado < flag) //para passar nas exceções
					return (-flag);
				flag += resultado;		
			}
		}
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

	flag = 0;	
	num = ft_printf_flag_number_value(fmt_beg, *fmt_end) - ft_strlen(ft_itoa(argumento));
	flag = ft_printf_flag_characters(fmt_beg, *fmt_end) ;//ALTERANDO AQUI

int teste = ft_printf_flag_number_value(fmt_beg, *fmt_end); //Possui valor
	
	if (flag == 1)//Flag '-'
		size += ft_writenbr(argumento) + ft_writestr(ft_writemalloc(num, ' '));
	if (flag == 10)//Flag '0'
		size += ft_writestr(ft_writemalloc(num, '0')) + ft_writenbr(argumento);
	if ((flag >= 1000 && flag <= 1111 && num < 0 && !teste) || ((flag == 101001 || flag == 101000 || flag == 101010) && *(fmt_end - 1) == '*'))//Flag '*'
	{
		char *arg = ft_itoa(va_arg(args, int));
		if (flag == 1000 || flag == 101000)//flag '*' e 
			size += ft_writestr(ft_writemalloc(argumento - ft_strlen(arg), ' ')) + ft_writestr(arg); 
		if (flag == 1010)//Flag '0*'
			size += ft_writestr(ft_writemalloc(argumento - ft_strlen(arg), '0')) + ft_writestr(arg);
		if (flag == 1001)//Flag '-*'
			size += ft_writestr(arg) + ft_writestr(ft_writemalloc(argumento - ft_strlen(arg), ' '));
		if (flag == 101010)
			size += ft_writechar(' ') + ft_writestr(ft_writemalloc(argumento - ft_strlen(arg) - 1, '0')) + ft_writestr(arg);
		if (flag == 101001)
			size += ft_writechar(' ') + ft_writestr(arg) + ft_writestr(ft_writemalloc(argumento - ft_strlen(arg) - 1, ' '));
	}
	else if((flag >= 1000 && flag <= 1111) || flag >= -1000)
		while (*fmt_beg != *(fmt_end + 1))
		{
			if (*fmt_beg == '*' && !(*(fmt_beg - 1) >= '1' && *(fmt_beg - 1) <= '9'))
				size += ft_writenbr(argumento);
			else
				size += ft_writechar(*fmt_beg);
			fmt_beg++;
		}
	else //Quando só número printa os espaços	
	{
		size += ft_writestr(ft_writemalloc(num, ' ')) + ft_writenbr(argumento) + ft_writestr("oi");
	}

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
