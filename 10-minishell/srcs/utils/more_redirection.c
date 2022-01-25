/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:04:18 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/14 18:04:20 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	finish_him_foreal(t_red *red)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
		perror("fork ");
	if (pid == 0)
	{
		red->ret = dup2(red->fd, 1);
		if (red->ret < 0)
		{
			perror("Dup2: ");
			exit(1);
		}
		do_cmd(red->cmd);
		exit(1);
	}
	else
	{
		close(red->fd);
		g_sh.last_output = waitpid(pid, &status, 0);
	}
}

void	finish_him(t_red *red)
{
	if (red->fd < 0)
	{
		perror("Open: ");
		exit(1);
	}
	if (g_sh.in_pipe == 1)
	{
		red_addback(g_sh.red, red);
		close(red->fd);
		return ;
	}
	finish_him_foreal(red);
}

void	right_token(t_red *red)
{
	char	**cmd_isvalid;

	cmd_isvalid = ft_bnessi_split(red->cmd, ' ');
	if (ft_strncmp(cmd_isvalid[0], "export", 6))
	{
		cmd_isvalid[0] = get_pipepath(cmd_isvalid[0]);
		if (!(ft_strncmp(cmd_isvalid[0], "error2", 6)))
			return ;
	}
	if (!(ft_strncmp(cmd_isvalid[0], "error", 5)))
	{
		printf("bash: %s: command not found\n", red->cmd);
		return ;
	}
	else if (!(ft_strncmp(red->token, ">>", 2)))
		red->fd = open(red->filename, O_RDWR | O_CREAT | O_APPEND, 0777);
	else
		red->fd = open(red->filename, O_RDWR | O_CREAT | O_TRUNC, 0777);
	finish_him(red);
}

void	finish_her(t_red *red)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
		perror("fork ");
	if (pid == 0)
	{
		red->ret = dup2(red->fd, 0);
		if (red->ret < 0)
		{
			perror("Dup2: ");
			exit(1);
		}
		do_cmd(red->cmd);
		exit(1);
	}
	else
	{
		close(red->fd);
		g_sh.last_output = waitpid(pid, &status, 0);
	}
}

void	left_token(t_red *red)
{
	char	**cmd_isvalid;

	if (!(g_sh.in_pipe) && (!(ft_strncmp(red->token, "<<", 2))))
		here_doc(red);
	else
	{
		cmd_isvalid = ft_bnessi_split(red->cmd, ' ');
		cmd_isvalid[0] = get_pipepath(cmd_isvalid[0]);
		if (!(ft_strncmp(cmd_isvalid[0], "error2", 6)))
			return ;
		else if (!(ft_strncmp(cmd_isvalid[0], "error", 5)))
			if ((printf("bash: %s: command not found\n", red->cmd)) > 0)
				return ;
		if (!(ft_strncmp(red->token, "<", 1)))
			red->fd = open(red->filename, O_RDONLY, 0777);
		if (red->fd < 0)
		{
			perror("Open: ");
			return ;
		}
		finish_her(red);
	}
}
