/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 23:31:23 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/05/15 01:33:08 by camilo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		ft_print_d(t_flags data, va_list args)
{
	if (data.minus == 0 && data.zero == 0 && data.star == 0
			&& data.point == -1 && data.width == 0)
		return (ft_putnbr(va_arg(args, int)));
	return (0);
}
