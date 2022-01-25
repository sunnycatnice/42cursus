/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:03:18 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exp_exists(char *name)
{
	t_node	*node;

	node = *g_sh.exp;
	if (!(node))
		return (0);
	while (node)
	{
		if (!(ft_strncmp(name, node->name, ft_strlen(name))))
			return (1);
		node = node->next;
	}
	return (0);
}

char	*remove_quotes(char *path)
{
	char	*ret;

	if (path[0] == '"')
		ret = double_quotes(path);
	else if (path[0] == 047)
		ret = single_quote(path);
	else
		return (path);
	return (ret);
}

char	*get_pwdpath(char *name)
{
	t_node	*node;
	char	*path;

	node = *g_sh.node;
	while (node)
	{
		if (!(ft_strncmp(node->name, "PWD", 3)))
			path = ft_strdup((char *)node->string);
		node = node->next;
	}
	path = ft_append(path, name, '/');
	return (path);
}

void	red_addback(t_red **lst, t_red *new)
{
	t_red	*red;

	if (!(*lst))
		*lst = new;
	else
	{
		red = *lst;
		while (red->next != NULL)
			red = red->next;
		red->next = new;
		new->prev = red;
	}
}

void	start_red(void)
{
	t_red	*red;

	red = malloc(sizeof(t_red *));
	red->fd = 0;
	red->start = 0;
	red_addback(g_sh.red, red);
}
