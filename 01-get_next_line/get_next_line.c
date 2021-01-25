 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:17:50 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/20 19:07:58 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*del_line(char *db)
{
	char	*newdb; //create a new database
	int		i; //database index
	int		j; //new_database index

	i = 0; // inizialising
	j = 0;
	if (!db) //if database doesn't exist
		return (0);
	while (db[i] && db[i] != '\n') //if database is scrolling and it did't reach EOL
		i++; //scroll index
	if (!db[i]) //if database in the index position doesn't exist
	{
		free(db);//free database
		return (0);
	}
	if (!(newdb = malloc(sizeof(char) * ((ft_strlen(db) - i) + 1)))) //inizialise and allocate neccessary
		//memory for the new database
		return (0);
	i++;
	while (db[i]) //while database exists
		newdb[j++] = db[i++]; //save de content of database in new database WHILE incrementing
	newdb[j] = '\0'; //addind EOL
	free(db);//freeing the 'old' database
	return (newdb); //returning new database
}

char    *next_line(char *db)
{
    size_t	index; //create an index to scroll
	char	*line;

	index = 0;
	if (!db) //if database doesn't exist
		return (0);
	while (db[index] && db[index] != '\n') //while database exist && has not reached EOL
		index++; // scroll index
	if (!(line = malloc(sizeof(char) * (index + 1)))) //not, inizialize line = allocate index + 1 (?)
		return (0);
	index = 0;//reset index counter, ready to count again, this time to copy an array
	while (db[index] && db[index] != '\n') // equal to previous while
	{
		line[index] = db[index]; //write db[i] char into line[i] static char
		index++;//scroll index
	}
	line[index] = '\0';//EOL
	return (line);//return copied line from database using index
}

int get_next_line(const int fd, char **line)
{
	char		*buffer; //prendere i caratteri temporaneamente
	static char	*db[MASSIMO_OPEN]; //puntatore a database con taglia massima
	int			res; //what has been read

	res = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!( buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!is_line(db[fd]) && res != 0) //while line not ended and there's something to read
	{
		if((res = read (fd, buffer, BUFFER_SIZE)) == -1) // if there's an error in reading
		{
			free(buffer);// free buffer memory
			return (-1);// return errror
		}
		buffer[res] = '\0'; // add terminating char
		db[fd] = ft_strjoin(db[fd], buffer); //join database w/ buffer
	}
	free(buffer); //free buffer memory
	*line = next_line(db[fd]); // coping  the content of the database to *line
	db[fd] = del_line(db[fd]); // deleting the database
	if (res == 0)
		return (0);
	return (1);// if all steps are correct, return 1
}
