/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:10:57 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/14 18:10:59 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_string(t_node *node, char *string)
{
	node->string = string;
}

void	create_node(t_node **node, char *name)
{
	t_node	*new;

	new = malloc(sizeof(t_node *));
	new->name = name;
	new->string = NULL;
	new->next = NULL;
	ft_lstaddnode_back(node, new);
}

void	put_data_in_node(t_node **node, char *ref, char *data)
{
	t_node	*p;

	p = (*node);
	while (p && (ft_strncmp(p->name, ref, ft_strlen(ref)) > 0))
		p = p->next;
	if (p)
		p->string = ft_strdup(data);
}

int	ft_lstsize(t_node *p)
{
	int	i;

	if (!(p))
		return (0);
	i = 0;
	if (p->next != NULL)
	{
		while (p)
		{
			i++;
			p = p->next;
		}
	}
	return (i);
}
