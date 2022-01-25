/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:44:14 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_existance_var(char *id)
{
	t_node	*p;

	p = *g_sh.var;
	if (!(p))
		return (0);
	while (p)
	{
		if (!(ft_strncmp(p->name, id, ft_strlen(id))))
			return (1);
		p = p->next;
	}
	return (0);
}

void	new_var(char *name, char *content)
{
	t_node	*new;

	new = malloc(sizeof(t_node *));
	new->name = ft_strdup(name);
	new->string = ft_strdup(content);
	printf("%s %s\n", new->name, new->string);
	new->next = NULL;
	ft_lstaddnode_back(g_sh.var, new);
}

void	put_data_var(char *line)
{
	int		i;
	char	*name;
	char	*content;

	i = 0;
	name = malloc(sizeof(char *));
	while (line[i] != '=')
	{
		name[i] = line[i];
		i++;
	}
	content = ft_substr(line, i + 1, ft_strlen(line) - ft_strlen(name) - 1);
	if ((check_existance_var(name)) != 0)
		continue_put_data_var(name, content);
	else
		new_var(name, content);
	free(content);
	free(name);
}

int	check_existance_exp(char *id)
{
	t_node	*p;

	p = *g_sh.exp;
	while (p)
	{
		if (!(ft_strncmp(p->name, id, ft_strlen(id))))
			return (1);
		p = p->next;
	}
	return (0);
}

void	put_data_exp(char *line)
{
	int		i;
	char	*name;
	char	*content;

	i = 0;
	while (line[i] != '=')
		i++;
	name = ft_substr(line, 0, i);
	content = ft_substr(line, (ft_strlen(name) + 1), ft_strlen(line));
	finish_adding(name, content);
	free(content);
	free(name);
}
