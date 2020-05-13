#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t		ft_strwidth(const char *s)
{
	int	i;
  int d;

  d = 0;
	i = 0;
	while (s[i])
  {
    if (s[i] == '\t' || s[i] == '\n' || s[i] == '\r' ||
        s[i] == '\v' || s[i] == '\f' || s[i] == ' ')
      d++;
    i++;
  }
	return (i - d);
}


size_t		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

char	*ft_strdup(const char *s1)
{
	char	*s1_copy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	s1_copy = malloc((len + 1) * sizeof(char));
	i = 0;
	if (s1_copy == 0)
		return (0);
	while (i < len)
	{
		s1_copy[i] = s1[i];
		i++;
	}
	s1_copy[i] = '\0';
	return (s1_copy);
}

typedef struct
{
	int			minus;
	int			zero;
	int			dot;
	int			star;
	int			type;
	int			width;
}				Content;


static Content		ft_datainit(void)
{
	Content			data;

	data.minus = 0;
	data.zero = 0;
	data.dot = -1;
	data.star = 0;
	data.type = 0;
	data.width = 0;
	return (data);
}

int					ft_putdata(const char *str, va_list args)
{
	Content			data;
	int				i;
	int				count;

  // data.text = input;
  // data.width = ft_strwidth(data.text);
  // printf("%d", data.width);
  // data.min = ft_atoi(input);

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
			count += ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			data = ft_datainit();
			i = ft_check(str, ++i, &data, args);
			if (ft_isconversion(str[i]))
				count += ft_handler((char)data.type, data, args);
			else if (str[i])
				count += ft_putchar(str[i]);
		}
		i++;
	}
	return (count);
}


int     ft_printf(const char *input, ...)
{
  va_list			args;
	int				count;
	char			*str;

	count = 0;
	if (!(str = ft_strdup(input)))
		return (0);
	va_start(args, input);
	count += ft_putdata(str, args);
	va_end(args);
	free((char *)str);
	return (count);
}

int   main()
{
  ft_printf("teste\n");
}
