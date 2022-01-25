/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:51:42 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/14 17:51:44 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_cderror(char *string)
{
	string = ft_space_remove(string);
	printf("cd: no such user or named directory: %s\n", string);
}

int	mini_squig(char *path, int i)
{
	while (path[i] == ' ')
	{
		if (path[i + 1] == '/')
		{
			ft_print_cderror(ft_substr(path, i, ft_strlen(path) - i));
			return (0);
		}
		i++;
	}
	if (!(path[i]))
		return (1);
	return (2);
}
