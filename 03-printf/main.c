#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int	val0, val1;
	//int i = 66472;
	//char anna [] = "na";
	//int *pointer = &i;
	//long uns =  9845997235;
	
	val0 = printf("%% *.5i 42 == |%        *.5i|\n", 4, 42);
	val1 = ft_printf("%% *.5i 42 == |%   *.5i|\n", 4, 42);

	printf("Return : (%d //", val0);
	printf(" %d)\n", val1);

	return (0);
}
