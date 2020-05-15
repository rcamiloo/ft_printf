//#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>




typedef struct
{
      char type;
      int minus;
      int zero;
      int star; // nao existir 0/precisao 1/ largura 2/ ambos 3
      int point;
      int width;

}flags;

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
	long x;
	x = nb;

	if (x < 0)
	{
		write(1, "-", 1);
		x = x * -1;
	}

	if (x / 10 > 0)
	{
		ft_putnbr(x / 10);
	}
	ft_putchar(x % 10 + '0');
}

int		ft_atoi(const char *str)
{
	int i;
	int n;
	int sinal;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	sinal = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sinal = 1;
		i++;
	}
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (sinal > 0)
		n = n * (-1);
	return (n);
}

int ft_print_d(flags data, va_list args)
{
       	if (data.minus == 0 && data.zero == 0 && data.star == 0 && data.point == -1 && data.width == 0)
	{
		ft_putnbr(va_arg(args, int));
	}
}

int ft_print_flag(flags data, va_list args)
{
  if (data.type == 'd' || data.type == 'i')
  {
    ft_print_d(data, args);
    //printf("data minus = %d\n", data.minus);
    //printf("zero = %d\n", data.zero);
    //printf("star =%d\n", data.star);
    //printf("point = %d\n", data.point);
    //printf("width = %d\n", data.width);
  }

}

int	ft_isnum(char n)
{
	if (n < '0' || n > '9')
		return  (0);
	return (1);
}

int     ft_isconversion(int c)
{
    return (c == 'c' || c == 's' || c == 'p' || c == 'd'
			|| c == 'i' || c == 'u' || c == 'x' || c == 'X');
}

int ft_read_flag(flags *data, const char *str)
{
  int i;

  i = 0;
  while ((str[i] == '-' || str[i] == '*' || ft_isnum(str[i]) || str[i] == '.'))
    i++;
  if (!(ft_isconversion(str[i])))
    return (-1);
  data->type = str[i];
  i = 0;
  if (str[i] == '0')
  {
    data->zero = 1;
    i++;
  }
  if (str[i] == '-')
  {
    data->minus = 1;
    data->zero = 0;
    i++;
  }
  while (ft_isnum(str[i]))
  {
     data->width = (data->width * 10) + (str[i] - '0');
     i++;
  }
  if (str[i] == '*')
  {
    data->star == 1;
    i++;
  }
  if (str[i] == '.')
  {
    data->point = 0;
    i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
      data->point = (data->point * 10) + (str[i] - '0');
      i++;
    }
  }

  if (str[i] == '*' && data->point >= 0)
  {
    data->star = (data->star > 0) ? 3 : 2;
    i++;
  }
  return (i);
}

void ft_init_data(flags *data)
{
  data->type = '\0';
  data->minus = 0;
  data->zero = 0;
  data->star = 0; // nao existir 0/precisao 1/ largura 2/ ambos 3
  data->point = -1;
  data->width = 0;
}


int ft_printf(const char *str,...)
{
  va_list args;
  flags   data;
 int val;

 val = 0;
  va_start(args, str);
  while (*str)
  {
    if(*str == '%')
    {
      str++;
      ft_init_data(&data);
      if ((val = ft_read_flag(&data, str)) >= 0)
      {
	ft_print_flag(data, args);
	      //printf("val = %d\n", val);
       	str = str + val  + 1 ;//- 1 funciona ! como pode?
      }
    }
    else
    {
      ft_putchar(*str);
      str++;
    }
  }
}

int main(void)
{
  ft_printf("teste\n");
  printf("\n");
  ft_printf("teste %d ahahahsdnnsajknf\n", 1000);
  ft_printf("%d<<< texto texto\n", 2147483,647);
  ft_printf("%d<<<basdhsa\n", -2147483648);
  ft_printf("%*.*z<<<basdhsa\n", 1);
  printf("%*.*z<<<basdhsa\n", 1);
  printf("teste\n");
  return (0);
}
