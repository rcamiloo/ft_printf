#include "libftprintf.h"

#include <stdio.h>
char	*ft_writemalloc(int len, char c)
{
	char *ptr;
	if (len < 0) 
		return (NULL);
	
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (len-- >=  0)
		ptr[len] = c;
	return (ptr);
}
