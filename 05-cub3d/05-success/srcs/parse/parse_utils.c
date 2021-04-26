/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:37:29 by dmangola          #+#    #+#             */
/*   Updated: 2021/04/26 17:37:37 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	ft_perror(char *error)
{
	ft_red_color();
	printf("%s", error);
	ft_reset_color();
	exit(-1);
}

int	matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		i++;
	}
	return (i);
}

void	free_matrix(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int	is_map(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n')
		return (0);
	return (1);
}

char	*ft_append(char *dst, char *src)
{
	int	i;

	i = (int)ft_strlen(dst);
	dst = (char *)ft_realloc(dst, ft_strlen(src) + ft_strlen(dst) + 2);
	dst[i] = '\n';
	ft_strcpy(&dst[i + 1], src);
	return (dst);
}
