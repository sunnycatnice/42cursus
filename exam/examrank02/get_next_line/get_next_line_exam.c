#include <fcntl.h>
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

		if(fd < 0 || BUFFER_SIZE <= 0)
				return(NULL);
		save[0] = 0;
		while(read(fd, buf, 1) == 1)
		{
				save[i] = buf[0];
				save[i + 1] = 0;
				if (save[i] == '\n')
						break;
				i++;
		}
		if (save[0] == 0)
				return(NULL);
		line = malloc (i + 1);
		i = 0;
		while(save[i])
		{
				line[i] = save[i];
				i++;
		}
		line[i] = 0;
		return line;
}
