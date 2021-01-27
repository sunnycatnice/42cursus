/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:35:27 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/27 15:35:32 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define MAX_FD 4096

size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
int				is_line(char *str);
int				get_next_line(const int fd, char **line);

#endif
