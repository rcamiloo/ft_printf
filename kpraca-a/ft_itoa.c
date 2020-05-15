/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpraca-a <kpraca-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 16:09:31 by kpraca-a          #+#    #+#             */
/*   Updated: 2020/04/16 16:35:49 by kpraca-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_malloc(int len)
{
	char *ptr;

	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, len + 1);
	return (ptr);
}

static int	ft_decimallen(int n)
{
	int len;

	len = 0;
	if (n <= 0)
	{
		len++;
	}
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*ptr;
	int		len;

	len = ft_decimallen(n);
	ptr = ft_malloc(len);
	if (!ptr)
		return (NULL);
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		ptr[0] = '-';
		if (n == -2147483648)
		{
			ptr[len-- - 1] = '8';
			n = n / 10;
		}
		n = -n;
	}
	while (n != 0 && len >= 0)
	{
		ptr[len-- - 1] = n % 10 + 48;
		n = n / 10;
	}
	return (ptr);
}
