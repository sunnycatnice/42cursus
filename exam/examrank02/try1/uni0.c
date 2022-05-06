#include <unistd.h>

int ft_check(char *av, int i, char c)
{
		while (i-- >= 0)
		{
				if (av[i] == c)
						return 1;
		}
		return 0;
}

int main(int ac, char **av)
{
		int i = 0;
		int j = 0;

		if (ac == 3)
		{
				while(av[1][i])
				{
						if (ft_check(av[1], i, av[1][i]))
								write(1, &av[1][i], 1);
						i++;
				}
				while(av[2][j])
				{
						if (ft_check(av[1], i, av[2][j]) == 0 && ft_check(av[2], j, av[2][j]) == 0)
								write(1, &av[2][j], 1);
						j++;
				}
		}
		write(1, "\n", 1);
}
