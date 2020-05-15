/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpraca-a <kpraca-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:37:22 by kpraca-a          #+#    #+#             */
/*   Updated: 2020/05/02 17:29:17 by kpraca-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

int		ft_printf(const char *fmt, ...);
int		ft_writechar(char c);
int		ft_writenbr(int n);
int		ft_writestr(char *s);
char		*ft_writemalloc(int len, char c);

#endif
