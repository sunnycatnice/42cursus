#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

//main to test new get_next_line function

int	main(void)
{
	int fd = open("main.c", O_RDONLY);
	char *line;
	int i = 0;
	while (i++ < 23)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}

	close(fd);
}
//22
//23