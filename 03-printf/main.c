#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int	val0;
	int val1;
	//int i = 66472;
	//char anna [] = "na";
	//int *pointer = &i;
	//long uns =  9845997235;

	val0 = printf("%%   *p 42 == |%*p|\n", 4, (void*)209590960);
	val1 = ft_printf("%%   *p 42 == |%*p|\n", 4, (void*)209590960);

	printf("Return : (%d //", val0);
	printf(" %d)\n", val1);

	return (0);
}
