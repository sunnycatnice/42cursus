#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 1

//my gnl no cheat
int get_next_line(int fd)
{
    char save[999999];
    char    *line;
    char buf[1];
    int i;

    if (fd < 0 || BUFF_SIZE <= 0)
        return NULL;
    save[0] = 0;
    while(read(fd, buf[0], 1) == 1)
    {
        save[i] = buf[0];
        save [i + 1] = 0;
        if (save[i] == '\n')
            break;
        i++;
    }
    if (save[0] == 0)
        return NULL;
    i = 0;
    line = malloc(i + 1);
    while(save[i])
    {
        line[i] = save[i];
        i++;
    }
    return line;
}