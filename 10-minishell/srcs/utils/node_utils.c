/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:10:46 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (0);
	if (lst->next != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstaddnode_back(t_node **lst, t_node *new)
{
	t_node	*p;

	p = *lst;
	if (lst && *lst)
	{
		if (p->next != NULL)
			p = ft_lstlast(p);
		p->next = new;
	}
	else
		*lst = new;
}

void	ft_lstadd_back(t_node **lst, char *name)
{
	t_node	*last;
	t_node	*new;

	last = *lst;
	new = malloc(sizeof(t_node));
	new->name = malloc(sizeof(char *));
	new->name = ft_strdup(name);
	new->string = NULL;
	new->next = NULL;
	if (lst && *lst)
	{
		last = ft_lstlast(last);
		last->next = new;
	}
	else
		*lst = new;
}
