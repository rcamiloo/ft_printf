/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 23:55:42 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/05/15 00:13:09 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void ft_init_data(t_flags *data)
{
	data->type = '\0';
	data->minus = 0;
	data->zero = 0;
	data->star = 0; // nao existir 0/precisao 1/ largura 2/ ambos 3
	data->point = -1;
	data->width = 0;
}
