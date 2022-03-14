#include <unistd.h>
#define USED 1
#define PRINTED 2
#define TOFILLARRAY used[(unsigned char)av[i][j]]
#define PRINTELEMENT write(1, &av[i][j], 1);

int main(int ac, char **av)
{
	int used[255] = {0};
	int i  = 2, j = 0;
	if(ac ==3)
	{
		while(i > 0)
		{
			j = 0;
			while(av[i][j])
			{
				if (i == 2 && !TOFILLARRAY)
					TOFILLARRAY = USED;
				else if(TOFILLARRAY == USED && i == 1)
				{
					PRINTELEMENT;
					TOFILLARRAY = PRINTED;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
