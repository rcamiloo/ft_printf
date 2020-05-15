/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 23:31:23 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/05/15 02:31:15 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_print_flag(t_flags data, va_list args)
{
	if (data.type == 'd' || data.type == 'i')
		return (ft_print_d(data, args));
	return (0);
}

int	ft_read_flag(t_flags *data, const char *str)
{
	int i;

	i = 0;
	while ((str[i] == '-' || str[i] == '*' || ft_isnum(str[i])
				|| str[i] == '.'))
	{
		ft_check_flags (str[i], data);
		while (ft_isnum(str[i]))
		{
			if (data->point == 0)
				data->width = (data->width * 10) + (str[i] - '0');
			else
				data->point = (data->point * 10) + (str[i] - '0');
			i++;
		}
		i++;
	}
	if (!(ft_isconversion(str[i])))
			return (-1);
	data->type = str[i];
	data->len = i;
	return (i);
}

void	ft_check_flags (const char f, t_flags *data)
{
if (f == '0' && data->minus == 0 && data->width == 0)
			data->zero = 1;
		if (f == '-')
		{
			data->minus = 1;
			data->zero = 0;
		}
		if (f == '*')
		{
			if (data->point == 0)
				data->star = 1;
			else
				data->star = (data->star > 0) ? 3 : 2;
		}
		if (f == '.')
			data->point = 0;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	data;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
		if (*str == '%')
		{
			str++;
			ft_init_data(&data);
			if (ft_read_flag(&data, str) >= 0)
			{
				count = count + ft_print_flag(data, args);
				str = str + data.len + 1;
			}
		}
		else
		{
			ft_putchar(*str);
			str++;
			count++;
		}
	return (count);
}
