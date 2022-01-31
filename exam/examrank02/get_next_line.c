#include "get_next_line.h"

int get_next_line(char **line)
{
    char    buffer[512];
    int     reader , i = 0;
    if (read(0, &buffer[0], 0) < 0 || (!line))
        return (-1);
    while ((reader = read(0, &buffer[i], 1)) > 0 && buffer[i] != '\n')
        i++;
    buffer[i] = '\0';
    if (reader != -1 && (*line = malloc(i + sizeof(char))) && (i = -1))
    {
        while (buffer[++i])
            (*line)[i] = buffer[i];
        (*line)[i] = '\0';
    }
    return (reader > 0 ? 1 : reader);
}
