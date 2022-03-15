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