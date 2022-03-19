#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_print_s(char *str)
{
    int i = -1;

    while(str[++i])
        write(1, &str[i], 1);
    return i;
}

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

int ft_print_x(long long num)
{
    int len;
    int mod;
    ft_putnbr_base(num, "0123456789abcdef", 10);
    while(num /mod >= 16)
    {
        len ++;
        num /= 16;
    }
    return len;
}

int ft_print_d(long long num)
{
    int len;
    int mod;
    if (num < 0)
    {
        len++;
        write(1, '-', 1);
        num *= -1;
    }
    ft_putnbr_base(num, "0123456789", 10);
    while(num /mod >= 10)
    {
        len ++;
        num /= 10;
    }
    return len;
}

int ft_printf(char *str, ...)
{
    va_list arg;

    int i = 0;
    int ret = 0;
    va_start(arg, str);

    while(str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 'd')  
                ret += ft_print_d(va_arg(arg, int));
            else if (str[i] == 'x')
                ret += ft_print_x(va_arg(arg, unsigned int));
            else if (str[i] == 's')
                ret += ft_print_s(va_arg(arg, char *));
        }
        else
            ret += write(1, &str[i], 1);
        i++;
    }
    va_end(arg);
    return(ret);
}