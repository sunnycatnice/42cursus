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