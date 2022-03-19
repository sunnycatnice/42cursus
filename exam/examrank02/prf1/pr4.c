#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void ft_putnbr_base(long long num, char *base, int base_len)
{
    if (num < base_len)
        write(1, &base[num], 1);
    else
    {
        ft_putnbr_base(num / base_len, base, base_len);
        ft_putnbr_base(num % base_len, base, base_len);
    }
}

int ft_put_d(long long num)
{
    int len = 1;
    int mod = 1;

    if (num < 0)
    {
        write (1, '-', 1);
        num *= -1;
        len ++;
    }
    ft_putnbr_base(num, "0123456789", 10);
    while(len / mod >= 10)
    {
        len++;
        mod *= 10;
    }
    return len;
}

int ft_printf(char *str, ...)
{
    int i = 0;
    va_list arg;
    int ret = 0;

    va_start(arg, str);
    while(str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 'd')
                ret += ft_put_d(va_arg(str, int));
            if (str[i] == 'x')
                ret += ft_put_x(va_arg(str, int));
            if (str[i] == 's')
                ret += ft_put_s(va_arg(str, int));
        }
    }
}