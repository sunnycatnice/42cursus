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

static char	*ft_remains(char *db)
{
	char	*remains;
	int		index_remains;
	int		index_line;

	index_line = 0;
	index_remains = 0;
	if (!db)
		return (0);
	while (db[index_line] && db[index_line] != '\n')
		index_line++;
	if (!db[index_line])
	{
		free(db);
		return (0);
	}
	if (!(remains = malloc(sizeof(char) *
			((ft_strlen(db) - index_line) + 1))))
		return (0);
	index_line++;
	while (db[index_line])
		remains[index_remains++] = db[index_line++];
	remains[index_remains] = '\0';
	free(db);
	return (remains);
}

static char	*ft_copy_in_line(char *db)
{
	size_t		index;
	char		*line;

	index = 0;
	if (!db)
		return (0);
	while (db[index] && db[index] != '\n')
		index++;
	if (!(line = malloc(sizeof(char) * (index + 1))))
		return (0);
	index = 0;
	while (db[index] && db[index] != '\n')
	{
		line[index] = db[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	char		*buffer;
	static char	*db[MAX_FD];
	int			res;

	res = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!is_line(db[fd]) && res != 0)
	{
		if ((res = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[res] = '\0';
		db[fd] = ft_strjoin(db[fd], buffer);
	}
	free(buffer);
	*line = ft_copy_in_line(db[fd]);
	db[fd] = ft_remains(db[fd]);
	if (res == 0)
		return (0);
	return (1);
}
