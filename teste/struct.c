#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>



#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

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

int	ft_isnum(char n)
{
	if (n < '0' || n > '9')
		return  (0);
	return (1);
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

void	*ft_memset(void *dest, int c, size_t len)
{
	if (len > 0)
	{
		while (len--)
		{
			*(unsigned char *)(dest + len) = (unsigned char)(c);
		}
	}
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	ft_puthex(unsigned long int nb)
{
	char hex[16];
	int  tmp;
	int  i;

	ft_bzero(hex, 16);
	i = 0;
	while (nb)
	{
		tmp = nb % 16;
		hex[i] = (tmp + (tmp >= 10 ? ('a' - 10) : '0'));
		nb /= 16;
		i++;
	}
	while (i >= 1)
	{
	i--;
	ft_putchar(hex[i]);
	}
}

int		ft_toupper(unsigned int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
	}
	return (c);
}

int		ft_tolower(unsigned int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

size_t		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// void ft_printf_d(const char *input)
// {
//   input++;
//   if (*input == 'd' || *input == 'i')
//   {
//     input++;
//     d = va_arg(args, int);
//     if (d >= 0)
//       ft_putchar('+');
//     ft_putnbr(d);
//   }
//   ft_putchar(*input);
// }

typedef struct
{
    int zero;
    int minus;
    int precision;
    int width;
    char type;
} content;
​
void    init_content(content *f)
{
    f->zero = 0;
    f->minus = 0;
    f->precision = -1;
    f->width = 0;
    f->type = '\0';
}


int     ft_printf(const char *input, ...)
{
	int d;
	int valnum;
	int length;
	unsigned int x;
	char *s;
	unsigned long int p;
  content data;

	//valnum tem que ser o atoi do input
  init_content(&data);
	va_list args;
	va_start(args, input);
  data.width = strlen(input);
	while(*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			valnum = ft_atoi(input);
			if (*input == '%')
				ft_putchar(*input);
			if (*input == '+')
			{
				input++;
				if (*input == 'd' || *input == 'i')
				{
					input++;
					if (d >= 0)
						ft_putchar('+');
					ft_putnbr(va_arg(args, int));
				}
				ft_putchar(*input);
			}
			if (*input == '.')
			{
				input++;
				valnum = ft_atoi(input);
				/*while (valnum >= 0)
				{
					ft_printf("valnum = %d\n", valnum);
					valnum--;
				}*/
				if (*input == 's')
				{
					input++;
					ft_putchar(*input);
				}
			}
			if (*input == '-')
			{
				input++;
				valnum = ft_atoi(input);
				while (ft_isnum(*input))
					input++;
				if (*input == 'd' || *input == 'i')
				{
					input++;
					d = va_arg(args, int);
					ft_putnbr(d);
				}
				if (d < 0)
					valnum--;
				if (*input == 'c')
				{
					input++;
					ft_putchar((char)va_arg(args, int));
				}
				if (*input == 's')
				{
					input++;
					s = va_arg(args, char *);
					if (s == 0)
						ft_printf("(null)");
					else
						ft_printf(s);
				}
				length = ft_strlen(s);
				while (length >= 0)
				{
				length--;
				valnum--;
				}
				while (valnum > 1 && *input++ != '%')
				{
					ft_putchar(' ');
					valnum--;
				}
				ft_putchar(*input);

			}
			if (*input == '0')
			{
				input++;
				valnum = ft_atoi(input);
				while(ft_isnum(*input))
					input++;
				while (valnum > 1)
				{
					valnum--;
					ft_putchar('0');
				}

			}
			if (ft_isnum(*input) && *input != '0')
			{
				valnum = ft_atoi(input);
				while (ft_isnum(*input) && *input != '0')
				{
					input++;
				}
				//parte nova
				/*while (valnum > 0 && *input != '%')
				{
					if (*input == 's')
					{
						valnum--;
					}
					ft_putchar(' ');
					valnum--;
				}*/
				//fim parte nova
				if (*input == '%')
					ft_putchar('%');
				if(*input == '.')
				{
					input++;
					valnum = ft_atoi(input);
					s = va_arg(args, char *);
					d = 0;
					while (valnum > 0 && *s != '\0')
					{
						ft_putchar(s[d]);
						valnum--;
						d++;
					}
					input++;
					if (*input == 's')
					{
						input++;
						ft_putchar(*input);
					}

				}
			}
			if (*input == 'd' || *input == 'i')
			{
				ft_putnbr(va_arg(args, int));
			}
			if (*input == 'c')
			{
				ft_putchar((char)va_arg(args, int));
			}
			if (*input == 's')
			{
				s = va_arg(args, char *);
				if (s == 0)
					ft_printf("(null)");
				else
					ft_printf(s);
			}
			if (*input == 'x')
			{
				x = va_arg(args, unsigned int);
				ft_puthex(x);
			}
			if (*input == 'X')
			{
				x = va_arg(args, unsigned int);
				ft_puthex(x);
			}
			if (*input == 'p')
			{
				p = va_arg(args, unsigned long int);
				if (p == 0)
					ft_printf("(nil)");
				else
				{
					ft_printf("0x");
					ft_puthex(p);
				}
			}
			if (*input == 'u')
			{
				x = va_arg(args, unsigned int);
				ft_putnbr(x);
			}
		}
		else
			ft_putchar(*input);
		input++;
	}
	va_end(args);
	return (0);
}


int     main(void)
{
	int i = 3;
	int n = -1;
	char c = 'k';
	char *s ="hello world";
	int hex =0xfafa;


	ft_printf("\n");
	ft_printf("VALORES = i = %d / n = %d / c = %c / *s = %s / hex = %x\n", i, n, c, s, hex);
	ft_printf("\n");
	ft_printf("<<<<<<<<<<<<<<<<<<<<<<<<<<< CONVERSIONS >>>>>>>>>>>>>>>>>>>>>>>>>\n");
	ft_printf("\n");
	ft_printf("====================( int d int i )==================\n");
	ft_printf("\n");
	ft_printf("	d = %d / i = %i			<ft_printf\n", i, i);
	printf("	d = %d / i = %i			<printf\n", i, i);
	ft_printf("\n");
	ft_printf("=================( char c )====================\n");
	ft_printf("\n");
	ft_printf("	this is char c -> %c	<ft_printf\n", c);
	printf("	this is char c -> %c	<printf\n", c);
	ft_printf("\n");
	ft_printf("===================( str s )===================\n");
	ft_printf("\n");
	ft_printf("	%s		<ft_printf\n", s);
	printf("	%s		<printf\n", s);
	ft_printf("\n");
	ft_printf("==================( hex x )====================\n");
	ft_printf("\n");
	ft_printf("	x = %x d = %d	<ft_printf\n", hex, hex);
	printf("	x = %x d = %d	<printf\n", hex, hex);
	ft_printf("	X = %X		<ft_printf\n", hex);
	printf("	X = %X		<printf\n",  hex);
	ft_printf("\n");
	ft_printf("==========( unsigned long int * p )=============\n");
	ft_printf("\n");
	ft_printf("	str ptr = %p		<ft_printf\n", s);
	printf("	str ptr = %p		<printf\n", s);
	ft_printf("\n");
	ft_printf("=================( unsigned int u )==============\n");
	ft_printf("\n");
	ft_printf("	i = %u		<ft_printf\n", i);
	printf("	i = %u		<printf\n", i);
	ft_printf("	n = %u		<ft_printf\n", n);
	printf("	n = %u		<printf\n", n);
	ft_printf("	hex = %u	<ft_printf\n", hex);
	printf("	hex = %u	<printf\n", hex);
	ft_printf("\n");
	ft_printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<< FLAGS >>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	ft_printf("\n");
	ft_printf("===================( + )=====================\n");
	ft_printf("\n");
	ft_printf("	flag + = %+d positivo	<ft_printf\n", i);
	printf("	flag + = %+d positivo	<printf\n", i);
	ft_printf("	flag + = %+d negativo	<ft_printf\n", n);
	ft_printf("	flag + = %+d negativo	<printf\n", n);
	ft_printf("	flag + = %+d zero	<ft_printf\n", 0);
	printf("	flag + = %+d zero	<printf\n", 0);
	ft_printf("\n");
	ft_printf("===================( - )=====================\n");
	ft_printf("\n");
	ft_printf("	flag - = %-10dfim positivo	<ft_printf\n", i);
	printf("	flag - = %-10dfim positivo	<printf\n", i);
	ft_printf("	flag - = %-1dfim positivo		<ft_printf\n", i);
	printf("	flag - = %-1dfim positivo		<printf\n", i);
	ft_printf("	flag - = %-5dfim negativo	<ft_printf\n", n);
	printf("	flag - = %-5dfim negativo	<printf\n", n);
	//printf("	flag - = %-0dfim zero		<printf\n", i);
	ft_printf("\n");
	ft_printf("===================( 0 )=====================\n");
	ft_printf("\n");
	ft_printf("	flag 02 = %02d		<ft_printf\n", i);
	printf("	flag 02 = %02d		<printf\n", i);
	ft_printf("	flag 010 = %010d	<ft_printf\n", i);
	printf("	flag 010 = %010d	<printf\n", i);
	ft_printf("	flag 01 = %01d		<ft_printf\n", i);
	printf("	flag 01 = %01d		<printf\n", i);
	//ft_printf("flag 00 = %00d	<ft_printf\n", i);
	//printf("flag 00 = %00d		<printf\n", i);
	ft_printf("\n");
	ft_printf("=========== << novos testes >> ================\n");
	ft_printf("\n");
	ft_printf("%5%<<\n");
	printf("%5%<<\n");
	ft_printf("	%-c	<ft_printf\n", c);
	printf("	%-c	<printf\n", c);
	ft_printf("	%p	<ft_printf\n", NULL);
	printf("	%p	<printf\n", NULL);
	ft_printf("%-5s<<\n","goes over");
	printf("%-5s<<\n","goes over");
	ft_printf("%5s\n", NULL);
	printf("%5s\n", NULL);
	ft_printf("%1.4s<	<ft_printf\n", s);
	printf("%1.4s<	<printf\n", s);
	ft_printf("%.s<	<ft_printf\n", NULL);
	printf("%.s<	<printf\n", NULL);
	ft_printf("%-5%<\n");
	printf("%-5%<\n");
	ft_printf("%23s\n", NULL);
	printf("%23s\n", NULL);
	ft_printf("%.0s\n", "hello");
	printf("%.0s\n", "hello");
	return (0);
}
