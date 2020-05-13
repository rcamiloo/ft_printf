#include "libftprintf.h"
#include <stdarg.h>




typedef struct
{
      char type;
      int minus;
      int zero;
      int star; // nao existir 0/precisao 1/ largura 2/ ambos 3
      int point;
      int num;

}flags;

int ft_print_flag(flags, agrs)
{
  if (data.type == 'd')
  {
    ft_print_d(data, va_arg(args, int));
  }

}

int ft_read_flag(data, str)
{
  int i;

  i = 0;
  while (!(str[i] == '-' || str[i] == '*' || ft_isnum(str[i]) || str[i] == '.'))
    i++;
  if (!(ft_isconversion(str[i])))
    return (0);
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
  if (str[i] >= '0' && str[i] <= '9')
  {
    while (str[i] >= '0' && str[i] <= '9')
    {
      data->width = (data->width * 10) + (str[i] - '0');
      i++;
    }
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
      if (flags)
      {
        ft_print_flag(flags, agrs);
      }
    }
    else
    {
      ft_putchar(*str);
    }
    str++;
  }
}
