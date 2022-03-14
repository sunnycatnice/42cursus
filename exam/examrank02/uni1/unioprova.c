#include <unistd.h>
#define USED 1
#define TOFILLARRAY tofill[(unsigned char)av[i][j]]
#define PRINTCHAR write(1, &av[i][j], 1)

int main (int ac, char **av)
{
		int tofill[255] = { 0};
		int i = 1, j = 2;

		if (ac == 3)
		{
				while (i < 3)
				{
						j = 0;
						while(av[i][j])
						{
							if(!TOFILLARRAY)
							{
								TOFILLARRAY = USED;
								PRINTCHAR;
							}
							j++;
						}
					i++;
				}
		}
		write(1, "\n", 1);
		return 0;
}
