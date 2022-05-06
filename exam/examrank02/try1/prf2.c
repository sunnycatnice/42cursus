#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_putstring(char *str)
{
		int i = 0;
		while(str[i])
		{
				write(1, &str[i], 1);
				i++;
		}
		return i;
}

void ft_putnbr_base(long long num, char *base, int base_len)
{
	if (num < base_len)
			write(1, &base[num], 1);

	else
	{
			ft_putnbr_base(num/base_len, base, base_len);
			ft_putnbr_base(num%base_len, base, base_len);
	}
}

int ft_put_d(int num)
{
	int len = 1;
	int mod = 1;

	if(num < 0)
	{
			len++;
			write(1, "-", 1);
			len++;
	}
	ft_putnbr_base(num, "0123456789", 10);
	while(num /mod >=10)
	{
			len++;
			mod*= 10;
	}
	return len;
}

int ft_put_x(int num)
{
	int len = 1;
	int mod = 1;

	ft_putnbr_base(num, "0123456789abcdef", 16);
	while(num /mod >=16)
	{
			len++;
			mod*= 16;
	}
	return len;
}

int ft_printf(char *str, ...)
{
		va_list arg;
		int ret = 0;
		int i = 0;

		va_start(arg, str);
		while(str[i])
		{
				if (str[i] == '%')
				{
						i++;
						if (str[i] == 'd')
								ret += ft_put_d(va_arg(arg, int));
						if (str[i] == 's')
								ret += ft_putstring(va_arg(arg, char *));
						if (str[i] == 'x')
								ret += ft_put_x(va_arg(arg, unsigned int));
				}
				else
						ret += write(1, &str[i], 1);
				i++;
		}
		va_end(arg);
		return ret;
}

int main()
{
		int i = 29392;
		printf("%d", ft_printf("sono la d %d sono la %s sono la x %x", i, "ciao", i));
		printf("%d", printf("sono la d %d sono la %s sono la x %x", i, "ciao", i));
}
