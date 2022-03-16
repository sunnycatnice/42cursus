#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1

char *get_next_line(int fd)
{
    char save[999999];
    int  i = 0;
    char buf[1];
    char *line;
    
    if (fd < 0 || BUFF_SIZE <= 0)
        return NULL;
    save[0] = 0;

    while(read(fd, buf, 1) == 1)
    {
        save[i] = buf[0];
        save[i+1] = 0;
        if (save[i] == '\n')
            break;
        i++;
    }
    if (save[0] == 0)
        return NULL;
    line = malloc (i + 1);
    i = -1;
    while(save[++i])
        line[i] = save[i];
    line[i] = 0;
    return line;
}