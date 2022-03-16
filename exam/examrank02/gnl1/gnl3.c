#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 1

char *get_next_line(int fd)
{
    char save[999999];
    char buf[1];
    int i;
    char *line;

    //check fd and bufsize
    if(fd<0||BUFF_SIZE<=0)
        return NULL;
    //init the first char to null terminating char
    save[0] = 0;
    //if the char read is ok, continue readinf
    while (read(fd, buf, 1) == 1)
    {
        //save in save che buf[0];
        save[i] = buf[0];
        //and the next save = to null terminating char
        save[i + 1] = 0;
        //the saved char is newline, exit the loop
        if (save == '\n')
            break;
        //++
        i++;
    }
    //check if something is saved
    if(save[0] == 0)
        return NULL;
    //malloc the correct space for line
    line = malloc(i + 1);
    i = 0;
    //loop through the save array, and save the chars in line
    while (save[i])
    {
        line[i] = save[i];
        i++;
    }
    //null terminating char to the last element of line
    line[i] = 0;
    //return line
    return line;
    
}