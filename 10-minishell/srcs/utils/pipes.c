/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:48:44 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	figlio(t_pipe *pipe, char *line)
{
	if ((dup2(pipe->fd[1], 1) < 0))
		exit(1);
	if (pipe->prev != NULL && ((dup2(pipe->prev->fd[0], 0) < 0)))
		exit(1);
	do_cmd(line);
	exit(1);
}

void	padre(int pid, t_pipe *p, int open)
{
	pid = 0;
	g_sh.last_output = wait(0);
	if (open)
	{
		close(p->fd[1]);
		if (p->next == NULL)
			close(p->fd[0]);
	}
	if (p->prev != NULL)
		close(p->prev->fd[0]);
	if (g_sh.pipe.pipe_nbr == 0 && (g_sh.close_helper == 1))
		close(p->fd[1]);
}

void	finish_pipes(int is_open, t_pipe *p, t_red *red)
{
	if (red != NULL)
	{
		if (!(ft_strncmp(red->token, "<<", 2)))
		{
			g_sh.here_file_helper = 1;
			here_doc(red);
			close(p->fd[0]);
			p->fd[0] = open("tmp", O_RDONLY, 0777);
		}
		else if (!(ft_strncmp(red->token, "<", 1)))
		{
			if (!(ft_strncmp(red->cmd, "wc", 2)))
				p->cmd = "cd";
			else
				p->cmd = red->cmd;
		}
	}
	if (red && (g_sh.in_pipe == 1))
		p->fd[1] = get_fd_one(red, p->fd[1]);
	g_sh.standard_out = p->fd[1];
	ft_fork_pipe(p, is_open);
	g_sh.in_pipe = 0;
	g_sh.standard_in = 0;
	g_sh.standard_out = 1;
}

int	sort_pipes(void)
{
	t_pipe	*p;
	int		is_open;
	t_red	*red;

	p = *g_sh.pipes;
	g_sh.here_file_helper = 0;
	while (g_sh.pipe.pipe_nbr-- > 0)
	{
		red = NULL;
		is_open = 0;
		red = pipe_the_red(p->cmd);
		if (g_sh.pipe.pipe_nbr != 0)
		{
			is_open = 1;
			if (pipe(p->fd))
				return (0);
		}
		finish_pipes(is_open, p, red);
		p = p->next;
	}
	if (g_sh.here_file_helper == 1)
		do_cmd("rm tmp");
	return (1);
}

void	has_pipesandred(char *line)
{
	int		i;
	int		j;
	t_pipe	*new;

	i = 0;
	g_sh.pipes = malloc(sizeof(t_node **));
	*g_sh.pipes = NULL;
	g_sh.pipe.matrix = ft_bnessi_split(line, '|');
	g_sh.close_helper = 0;
	while (g_sh.pipe.matrix[i])
		i++;
	j = 0;
	while (j < i)
	{
		new = new_pipe(g_sh.pipe.matrix[j]);
		pipe_addback(g_sh.pipes, new);
		j++;
	}
	g_sh.pipe.pipe_nbr = j;
	launch_pipes();
	g_sh.close_helper = 0;
}
