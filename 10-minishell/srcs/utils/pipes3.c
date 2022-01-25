/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:05:52 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fork_pipe(t_pipe *p, int is_open)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror(" ");
		exit(0);
	}
	else if (pid == 0)
		figlio(p, p->cmd);
	else
		padre(pid, p, is_open);
}

t_red	*pipe_the_red(char *cmd)
{
	t_red	*red;

	red = NULL;
	if ((check_token_error(cmd)) == -2)
	{
		g_sh.in_pipe = 1;
		red = init_red(cmd);
	}
	return (red);
}
