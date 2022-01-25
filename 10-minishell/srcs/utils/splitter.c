/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:22:48 by bde-luca          #+#    #+#             */
/*   Updated: 2021/11/28 19:29:54 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_space_remove(char *line)
{
	int	i;

	i = 0;
	if (!(line) || (!(line[i])))
		return (0);
	while (line[i] == ' ' || line[i] == 9)
		i++;
	line = ft_substr(line, i, ft_strlen(line) - i);
	return (line);
}
