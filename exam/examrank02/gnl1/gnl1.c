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

    //check input errors
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    //save in "save" the read result from buf[0]
    save[0] = 0;
    while(read(fd, buf, 1) == 1)
    {
        //put the result of buf in save
        save[i] = buf[0];
        //init the next one char in 0
        save[i + 1] = 0;
        //check if NL, if so break
        if (save[i] == '\n')
            break;
        //i++
        i++;
    }

    //check if something is saved
    if (save[0] == 0)
        return NULL;

    //alloc the neccessary memory for line return
    line = malloc(i + 1);
    i = -1;
    //loop through save till the end to save the resoult in line
    while (save[++i])
        line[i] = save[i];
    //init the last element of line to 0, EOF
    line[i] = 0;

    //return 
    return line;
}