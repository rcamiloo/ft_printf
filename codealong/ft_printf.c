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


int ft_print_flag(flags data, va_list args)
{
  if (data.type == 'd')
  {
    // ft_print_d(data, va_arg(args, int));
    printf("data minus = %d\n", data.minus);
    printf("zero = %d\n", data.zero);
    printf("star =%d\n", data.star);
    printf("point = %d\n", data.point);
    printf("width = %d\n", data.width);
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
    return (0);
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
  if (ft_isnum(str[i]))
  {
    while (ft_isnum(str[i]))
    {
      data->width = (data->width * 10) + (str[i] - '0');
      i++;
    }
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


  va_start(args, str);
  while (*str)
  {
    if(*str == '%')
    {
      str++;
      ft_init_data(&data);
      if (ft_read_flag(&data, str))
      {
        str = str + ft_print_flag(data, args) - 1;//- 1 funciona ! como pode?
	
      }
    }
    else
    {
      ft_putchar(*str);
    }
    str++;
  }
}

int main(void)
{
  ft_printf("teste\n");
  ft_printf("teste %23d\n", 1);
  printf("teste\n");
  return (0);
}
