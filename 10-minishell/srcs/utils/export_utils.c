/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vceccaro <vceccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:56:46 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/22 19:35:26 by vceccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_err_name(char *string)
{
	int		i;
	int		j;
	char	*ret;

	ret = malloc(sizeof(char *));
	i = 1;
	j = 0;
	while (string[i])
	{
		ret[j] = string[i];
		i++;
		j++;
	}
	free(string);
	return (ret);
}

char	*takeout_spaces(char *id)
{
	int		i;

	i = 0;
	if (id[0] == '$')
		id = ft_substr(id, i, ft_strlen(id));
	else
	{
		while (id[i] == ' ')
			i++;
		id = ft_substr(id, i, ft_strlen(id));
	}
	return (id);
}

int	check_existance(char *id)
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

void	add_exp_info(char *name, char *string)
{
	t_node		*p;

	p = *g_sh.exp;
	while (p)
	{
		if (!(ft_strncmp(p->name, name, ft_strlen(name))))
		{
			p->string = ft_strdup(string);
			return ;
		}
		p = p->next;
	}
}

int	get_node(char *id)
{
	t_node	*exp;
	t_node	*var;

	exp = NULL;
	var = *g_sh.var;
	if (!(var))
		return (0);
	while (var)
	{
		if (!(ft_strncmp(id, var->name, ft_strlen(id))))
		{
			exp = malloc(sizeof(t_node));
			exp->name = ft_strdup(var->name);
			exp->string = NULL;
			exp->next = NULL;
			if (var->string)
				exp->string = ft_strdup(var->string);
			ft_lstaddnode_back(g_sh.exp, exp);
			return (1);
		}
		var = var->next;
	}
	return (0);
}
