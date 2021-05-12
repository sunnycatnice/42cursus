/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:02:38 by dmangola          #+#    #+#             */
/*   Updated: 2021/05/12 16:05:03 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_perror(char *error)
{
	ft_red_color();
	printf("%s", error);
	ft_reset_color();
	exit(-1);
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

char	*ft_append(char *dst, char *src)
{
	int	i;

	i = (int)ft_strlen(dst);
	dst = (char *)ft_realloc(dst, ft_strlen(src) + ft_strlen(dst) + 2);
	dst[i] = '\n';
	ft_strcpy(&dst[i + 1], src);
	return (dst);
}
