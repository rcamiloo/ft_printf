/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpraca-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:35:10 by kpraca-a          #+#    #+#             */
/*   Updated: 2020/03/10 19:45:03 by kpraca-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_writenbr(int n)
{
	int size;

	size = 0;
	if (n < 0)
	{
		size += ft_writechar('-');
		if (n == -2147483648)
		{
			size += ft_writechar('2');
			size += ft_writenbr(147483648);
			return (size);
		}
		n = -n;
	}
	if (n > 9)
		size += ft_writenbr(n / 10);
	size += ft_writechar(n % 10 + 48);

	return (size);
}
