//printf.c
//#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

void ft_putnbr_base(long long num,  char *base, int base_len)
{
	if (num < base_len)
		write(1, &base[num], 1);
	else
	{
		ft_putnbr_base(num / base_len, base, base_len);
		ft_putnbr_base(num % base_len, base, base_len);
	}
}

int	ft_print_d(long long num)
{
	int len = 1;
	int mod = 1;
	if (num < 0)
	{
		len++;
		write (1, "-", 1);
		num *= -1;
	}
	ft_putnbr_base(num, "0123456789", 10);
	while (num / mod >= 10)
	{
		len++;
		mod *= 10;
	}
	return (len);
}

int	ft_print_x(unsigned int num)
{
	int len = 1;
	int mod = 1;
	ft_putnbr_base(num, "0123456789abcdef", 16);
	while (num / mod >= 16)
	{
		len++;
		mod *= 16;
	}
	return (len);
}

int ft_printf(char *str, ...)
{
	va_list arg;
	int	i = 0;
	int	ret = 0;

	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'd')
				ret +=	ft_print_d(va_arg(arg, int));
			else if (str[i] == 'x')
				ret +=	ft_print_x(va_arg(arg, unsigned int));
			else if (str[i] == 's')
				ret += ft_putstr(va_arg(arg, char *));
		}
		else
			ret += write (1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (ret);
}


int main ()
{
	int len;
	int len2;

	len = ft_printf("S: %s D: %d X: %x\n", "ciao", -10, 42420);
	len2= printf("S: %s D: %d X: %x\n", "ciao", -10, 42420);
	printf("MIO: %d - VERO:  %d", len, len2);
}

//gnl.c
//#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1

char *get_next_line(int fd)
{
    char save[999999];
    char buf[1];
    char *line;
    int  i;

    i = 0;

    //check input errors
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    //save in "save" the read result from buf[0]
    save[0] = 0;
    while(read(fd, buf, 1) == 1)
    {
        //put the result of buf in save
        save[i] = buf[0];
        //init the next one char in 0
        save[i + 1] = 0;
        //check if NL, if so break
        if (save[i] == '\n')
            break;
        //i++
        i++;
    }

    //check if something is saved
    if (save[0] == 0)
        return NULL;

    //alloc the neccessary memory for line return
    line = malloc(i + 1);
    i = -1;
    //loop through save till the end to save the resoult in line
    while (save[++i])
        line[i] = save[i];
    //init the last element of line to 0, EOF
    line[i] = 0;

    //return
    return line;
}

//uni.c
#include <unistd.h>

int    ft_check_prev(int firstsecond, int i, char **av, char p)
{
    while(--i >= 0)
    {
        if (av[firstsecond][i] == p)
            return 0;
    }
    return 1;
}

int main(int ac, char **av)
{
    int i = 0, j = 0;

    if (ac == 3)
    {
        while (av[1][i])
        {
            if (ft_check_prev(1, i, av, av[1][i]) == 1)
                write(1, &av[1][i], 1);
            i++;
        }
        while(av[2][j])
        {
            if (ft_check_prev(1, i, av, av[2][j]) == 1 && ft_check_prev(2, j, av, av[2][j]) == 1 )
                write(1, &av[2][j], 1);
            j++;
        }
    }
    write(1, "\n", 1);
}

//int.c

#include <unistd.h>
#include <stdio.h>

//check if the char exist in the string
int     ft_check_string(char *str, char c)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

//check if any of the previous chars in the string was already printed
int    ft_check_prev(int firstsecond, int i, char **av, char p)
{
    while(--i >= 0)
    {
        if (av[firstsecond][i] == p)
            return 0;
    }
    return 1;
}

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 3)
    {
        while(av[1][i])
        {
            if (ft_check_prev(1, i, av, av[1][i]) == 1 && ft_check_string(av[2], av[1][i]) == 1 )
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}
