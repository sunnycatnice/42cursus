#include <unistd.h>

int main(int ac, char **av)
{
	int used[255] = {0};
	int i = 1, j = 0;
	if (ac == 3)
	{
		while(i < 3)
		{
			j = 0;
			while(av[i][j])
			{
				if(!used[(unsigned char)av[i][j]])
				{
					used[(unsigned char)av[i][j]] = 1;
					write(1, &av[i][j], 1);
				}
				j++;
			}
			i ++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
