/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:52:03 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_echo(char *name)
{
	t_node	*node;

	node = *g_sh.node;
	while (node)
	{
		if (!(ft_strncmp(name, node->name, ft_strlen(name))))
		{
			free(name);
			return ((char *)node->string);
		}
		node = node->next;
	}
	node = *g_sh.var;
	while (node)
	{
		if (!(ft_strncmp(name, node->name, ft_strlen(name))))
		{
			free(name);
			return ((char *)node->string);
		}
		node = node->next;
	}
	free(name);
	return (0);
}

int	get_i(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '>' || line[i] == '<')
	{
		i++;
		if (line[i] == '>' || line[i] == '<')
			i++;
		while (line[i] == ' ')
			i++;
		while (ft_strncmp(line, "echo", 4))
		{
			line = ft_substr(line, 1, ft_strlen(line) - 1);
			i++;
		}
		if (!(ft_strncmp(line, "echo", 4)))
			i += 4;
	}
	else
		i = 4;
	return (i);
}

int	ft_echo_helper(char *line, int i)
{
	if (line[i] == ' ')
	{
		while ((line[i] == ' ') || (line[i] == 34))
			i++;
	}
	return (i);
}
