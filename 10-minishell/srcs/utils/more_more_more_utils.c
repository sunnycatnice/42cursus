/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_more_more_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:44:14 by dmangola          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	finish_adding(char *name, char *content)
{
	t_node	*var;

	var = *g_sh.exp;
	while (var)
	{
		if (!(ft_strncmp(name, var->name, ft_strlen(name))))
		{
			var->string = ft_strdup(content);
			break ;
		}
		var = var->next;
	}
}

void	finish_read_line(char *input)
{
	if (input[0] == 047 && (input[1] != '$'))
		input = ft_strtrim(input, "'");
	if (input[0] == '"' )
		input = double_quotes(input);
	if (input[0] == '/')
		input = ft_checkif_path(input);
	g_sh.line = ft_strdup(input);
	free(input);
}

void	free_pipes(void)
{
	t_pipe	*p;
	t_pipe	*del;

	if (!(g_sh.pipes || !(*(g_sh.pipes))))
		return ;
	del = NULL;
	p = *g_sh.pipes;
	while (p)
	{
		del = p;
		free(del);
		p = p->next;
	}
}

void	launch_pipes(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		perror (" ");
	else if (pid == 0)
		sort_pipes();
	else
	{
		wait(0);
		free(g_sh.pipes);
		exit(1);
	}
}
