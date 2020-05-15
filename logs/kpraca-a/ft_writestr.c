/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpraca-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:04:42 by kpraca-a          #+#    #+#             */
/*   Updated: 2020/03/10 19:15:37 by kpraca-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_writestr(char *s)
{
	int size;

	if (s == NULL) // incluído esse if e return
		return (0);

	size = 0;
	while (*s != '\0')
	{
		size += ft_writechar(*s);
		s++;
	}

	return (size);
}
