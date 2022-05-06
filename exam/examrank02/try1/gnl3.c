#include <stdlib.h>

char *get_next_line(int fd)
{
		int i = 0;
		char *ret;
		char buf[2];
		char line[999999];

		if (fd < 0 || BUFFER_SIZE < 1)
				return NULL;
		line[0] = 0;
		while(read(fd, &buf[0], 1) == 1)
		{
				line[i] = buf[i];
				line[i+1] = 0;
				if(line[i] == '\n')
						break ;
				i++;
		}
		if (line[0] == 0)
				return NULL;
		i = 0;
		ret = malloc(i+1);
		while(line[i])
		{
				ret[i] = line[i]
				ret[i+1] = 0;
				i++;
		}
		return ret;
}
