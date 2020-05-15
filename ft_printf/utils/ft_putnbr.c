/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 23:57:30 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/05/15 00:54:37 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		ft_putnbr(int nb)
{
	long x;
	int count;

	x = nb;
	count = 1;
	if (x < 0)
	{
		write(1, "-", 1);
		x = x * -1;
		count++;
	}

	if (x / 10 > 0)
	{
		count = count + ft_putnbr(x / 10);
	}
	ft_putchar(x % 10 + '0');
	return (count);
}
