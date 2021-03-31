/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:17:50 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/27 15:42:12 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int ft_get_next_line(int fd, char **line)
{
    char    buffer[512];
    int     reader , i = 0;
    if (read(fd, &buffer[0], 0) < 0 || (!line))
        return (-1);
    while ((reader = read(fd, &buffer[i], 1)) > 0 && buffer[i] != '\n')
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