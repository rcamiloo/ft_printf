/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpraca-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:48:22 by kpraca-a          #+#    #+#             */
/*   Updated: 2020/01/27 19:18:30 by kpraca-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char *t;

	t = (char *)s;
	while (n > 0)
	{
		*t++ = 0;
		n--;
	}
}