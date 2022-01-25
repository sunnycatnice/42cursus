/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:43:03 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	matrix_check_unset(char **matrix)
{
	int		i;
	int		j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == '=')
			{
				if (j == 0)
					printf("bash: %s not found\n", get_err_name(matrix[i]));
				else
					printf("unset: %s: invalid parameter name\n", matrix[i]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	unset_envp(char *name)
{
	t_node	*unset;
	t_node	*bef;
	t_node	*aft;

	unset = *g_sh.node;
	aft = NULL;
	if (!(unset))
		return ;
	while (unset)
	{
		if (!(ft_strncmp(name, unset->name, ft_strlen(name))))
			unsetter(unset, bef, aft);
		bef = unset;
		unset = unset->next;
	}
}

void	unset_node(char *name)
{
	t_node	*unset;
	t_node	*bef;
	t_node	*aft;

	unset = *g_sh.exp;
	bef = NULL;
	aft = NULL;
	if (!(unset))
		return ;
	while (unset)
	{
		if (!(ft_strncmp(name, unset->name, ft_strlen(name))))
			unsetter(unset, bef, aft);
		bef = unset;
		unset = unset->next;
	}
	unset_envp(name);
}

int	unset_error(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_substr(line, 6, ft_strlen(line));
	while (tmp[i])
	{
		if (tmp[i] != ' ')
		{
			free(tmp);
			return (1);
		}
		i++;
	}
	free(tmp);
	return (0);
}

int	ft_unset(char *id)
{
	int		i;
	char	**matrix;

	if (!(unset_error(id)))
		return (0);
	id = ft_substr(id, 6, ft_strlen(id));
	matrix = ft_bnessi_split(id, ' ');
	i = 0;
	if (!(matrix_check_unset(matrix)))
	{
		free_matrix(matrix);
		return (0);
	}
	while (matrix[i] != NULL)
	{
		unset_node(matrix[i]);
		i++;
	}
	free_matrix(matrix);
	free(id);
	return (0);
}
