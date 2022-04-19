/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vceccaro <vceccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:39:37 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/22 21:14:32 by vceccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_red(char *cmd)
{
	t_red	*red;

	if ((check_token_error(cmd)) == -2)
	{
		red = init_red(cmd);
		cmd = ft_strdup(red->cmd);
	}
	return (cmd);
}

int	do_cmd(char *cmd)
{
	if (g_sh.in_pipe != 0)
		cmd = check_red(cmd);
	if (!(ft_strncmp(cmd, "return", 7)))
		return (0);
	else if (!(ft_strncmp(cmd, "pwd", 3)))
		return (g_sh.last_output = ft_pwd());
	else if (!(ft_strncmp(cmd, "echo", 4)))
		return (g_sh.last_output = ft_echo(cmd));
	else if (!(ft_strncmp(cmd, "cd", 2)))
		return (g_sh.last_output = ft_cd(cmd));
	else if (!(ft_strncmp(cmd, "env", 3)))
		return (g_sh.last_output = ft_env(1));
	else if (!(ft_strncmp(cmd, "export", 6)))
		return (g_sh.last_output = ft_export(cmd));
	else if (!(ft_strncmp(cmd, "$", 1)))
		return (g_sh.last_output = ft_dollaro(cmd));
	else if (!(ft_strncmp(cmd, "unset", 5)))
		return (g_sh.last_output = ft_unset(cmd));
	else if (!(ft_strncmp(cmd, "exit", 5)))
		return (g_sh.last_output = ft_exit());
	else
		return (g_sh.last_output = check_for_var(cmd));
	return (-1);
}

int	get_fd_one(t_red *red, int fd)
{
	if (!(ft_strncmp(red->token, ">>", 2)))
	{
		g_sh.close_helper = 1;
		close(fd);
		fd = open(red->filename, O_RDWR | O_CREAT | O_APPEND, 0777);
	}
	else if (!(ft_strncmp(red->token, ">", 1)))
	{
		g_sh.close_helper = 1;
		close(fd);
		fd = open(red->filename, O_RDWR | O_CREAT | O_TRUNC, 0777);
	}
	return (fd);
}

t_pipe	*new_pipe(char *line)
{
	t_pipe	*new;
	char	*tmp;

	new = malloc(sizeof(t_node));
	tmp = malloc(ft_strlen(line + 1));
	tmp = ft_strtrim(line, " ");
	new->cmd = ft_strdup(tmp);
	if (new->cmd[0] == '/')
		new->cmd = ft_checkif_path(new->cmd);
	new->next = NULL;
	new->prev = NULL;
	free(tmp);
	return (new);
}

void	pipe_addback(t_pipe **lst, t_pipe *new)
{
	t_pipe	*pipe;

	if (!(*lst))
		*lst = new;
	else
	{
		pipe = *lst;
		if (pipe->next != NULL)
		{
			while (pipe->next != NULL)
			{
				if (pipe->next == NULL)
					break ;
				pipe = pipe->next;
			}
		}
		pipe->next = new;
		new->prev = pipe;
	}
}
