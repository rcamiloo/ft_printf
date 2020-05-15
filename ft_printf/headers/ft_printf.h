/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 23:27:22 by rcamilo-          #+#    #+#             */
/*   Updated: 2020/05/15 02:28:11 by rcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

typedef struct	s_flags
{
	char	type;
	int		minus;
	int		zero;
	int		star;
	int		point;
	int		width;
	int		len;
}				t_flags;

void			ft_putchar(char c);
int				ft_putnbr(int nb);
void			ft_init_data(t_flags *data);
int				ft_atoi(const char *str);
int				ft_print_d(t_flags data, va_list args);
int				ft_print_flag(t_flags data, va_list args);
int				ft_isnum(char n);
int				ft_isconversion(int c);
int				ft_read_flag(t_flags *data, const char *str);
int				ft_printf(const char *str, ...);
void			ft_check_flags (const char f, t_flags *data);

#endif
