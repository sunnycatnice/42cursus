#include <unistd.h>

int ft_check_string(char *str, char c)
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

int ft_check_prev(int firstsecond, int i, char **av, char c)
{
    while (--i >= 0)
    {
        if (av[firstsecond][i] == c)
            return 0;
    }
    return 1;
}

int main(int ac, char **av)
{
    int i = 0;

    if(ac == 3)
    {
        while(av[1][i])
        {
            if (ft_check_prev(1, i, av, av[1][i]) == 1 && ft_check_string(av[2], av[1][i]))
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}