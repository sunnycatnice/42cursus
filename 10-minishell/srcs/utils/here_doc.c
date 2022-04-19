/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vceccaro <vceccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:58:12 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/22 19:44:25 by vceccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	finish_it_foreal(int fd, char *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork ");
		exit(0);
	}
	if (pid == 0)
	{
		if ((dup2(fd, 0)) < 0)
		{
			perror("Dup2: ");
			exit(0);
		}
		do_cmd(cmd);
		exit(0);
	}
	else
	{
		close(fd);
		g_sh.last_output = wait(0);
		do_cmd("rm tmp");
	}
}

void	finish_it(char **args, char *cmd)
{
	int		j;
	int		fd;
	pid_t	pid;

	fd = open("tmp", O_RDWR | O_CREAT | O_TRUNC, 0777);
	j = 0;
	pid = fork();
	if (pid < 0)
		perror("");
	else if (pid == 0)
	{
		dup2(fd, 1);
		while (args[j++] != NULL)
			printf("%s\n", args[j]);
		exit(1);
	}
	else
		if (!(close(fd)))
			g_sh.last_output = wait (0);
	if (g_sh.in_pipe == 1)
		return ;
	fd = open("tmp", O_RDONLY, 0777);
	finish_it_foreal(fd, cmd);
}

void	here_doc(t_red *red)
{
	char	**args;
	int		i;
	int		j;

	args = malloc(sizeof(100));
	i = 0;
	while (1)
	{
		args[i] = malloc(sizeof(char *));
		if (!(args[i]))
			return ;
		args[i] = readline("> ");
		if (!(ft_strncmp(args[i], red->filename, ft_strlen(red->filename))))
		{
			args[i] = NULL;
			break ;
		}
		i++;
	}
	finish_it(args, red->cmd);
	j = -1;
	while (++j < i - 1)
		free(args[j]);
}
