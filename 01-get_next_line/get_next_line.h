/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:19:38 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/24 12:17:53 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define MASSIMO_OPEN 4096

size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
int				is_line(char *str);
int				get_next_line(const int fd, char **line);
char			*next_line(char *db);
char			*del_line(char *db);

#endif
