/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:48:57 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_list(t_node **lst)
{
	t_node	*nextt;
	t_node	*current;

	if (!(*lst) || !lst)
		return ;
	current = *lst;
	while (current)
	{
		if (current->next != NULL)
			nextt = current->next;
		else
			nextt = NULL;
		if (ft_strlen(current->name) != 0)
			free(current->name);
		if (current->string != NULL && (ft_strlen(current->string) != 0))
			free(current->string);
		free(current);
		current = nextt;
	}
}

void	free_matrix(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	if (!(matrix))
		return ;
	while (matrix[i] != NULL)
		i++;
	j = 0;
	while (j < i)
	{
		free(matrix[j]);
		j++;
	}
	free(matrix[j]);
	free(matrix);
}

void	free_globals(void)
{
	int		i;

	i = 0;
	if (*g_sh.node)
		free_list(g_sh.node);
	if (*g_sh.var)
		free_list(g_sh.var);
	if (*g_sh.exp)
		free_list(g_sh.exp);
	free_matrix(g_sh.envp);
	free_matrix(g_sh.av);
	free(g_sh.line);
}

int	ft_exit(void)
{
	free_globals();
	printf("exit\n");
	exit(0);
}
