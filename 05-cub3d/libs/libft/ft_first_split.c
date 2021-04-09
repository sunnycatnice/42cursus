/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:54:46 by dmangola          #+#    #+#             */
/*   Updated: 2021/04/08 18:54:59 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_first_split(char *string)
{
	char	*first;
	int		i;
	int		j;

	j = 0;
	while (string[j] && ft_isspace(string[j]))
		j++;
	i = j;
	while (string[i] && !ft_isspace(string[j]))
		i++;
	first = malloc(((i - j) + 1) * sizeof(char));
	if (!first)
		return (NULL);
	i = 0;
	while (string[j + i] && !ft_isspace(string[j + i]))
	{
		first[i] = string[j + i];
		string[j + i] = ' ';
		i++;
	}
	first[i] = 0;
	return (first);
}
