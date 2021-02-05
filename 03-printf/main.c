#include "printf.h"
#include <stdio.h>
#include "ft_printf.c"

int main()
{
	char a = 'f';

	printf("Abbello %c\n", a);
	ft_printf("Abbello %c\n", a);
	return (0);
}
