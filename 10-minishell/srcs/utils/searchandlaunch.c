/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchandlaunch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:12:16 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*findrightpath(char **path, char **cmd)
{
	char	*line;
	int		i;

	i = 0;
	while (path[i])
	{
		line = get_pipepath(cmd[0]);
		if (open(line, O_RDONLY) >= 0)
			return (line);
		free(line);
		i++;
	}
	printf("Error: this command does not exist\n");
	return (0);
}

static void	ft_fork(char *path, char **cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("error ");
		exit(0);
	}
	if (pid == 0)
	{
		execve(path, cmd, g_sh.envp);
		exit(1);
	}
	else
		g_sh.last_output = wait(0);
	free_matrix(cmd);
	if (path)
		free(path);
}

int	protectline(char *line)
{
	char	**cmd;

	cmd = ft_bnessi_split(line, ' ');
	if (!cmd[0])
	{
		free_matrix(cmd);
		return (0);
	}
	free_matrix(cmd);
	return (1);
}

char	**pathfinder(char *line)
{
	int		i;
	char	*path;
	char	**cmd;
	int		status;

	i = 0;
	cmd = ft_bnessi_split(line, ' ');
	status = 0;
	path = 0;
	if (!(strncmp(cmd[0], "./", 2)))
	{
		path = ft_strdup(g_sh.pwd);
		cmd[0] = ft_strdup(cmd[0] + 1);
		path = ft_strjoin(path, cmd[0]);
	}
	else
		path = get_pipepath(cmd[0]);
	if (!(ft_strncmp(path, "error", 5)) || (!(ft_strncmp(path, "error2", 6))))
	{
		if (printf("bash: %s: command not found\n", cmd[0]))
			free_matrix(cmd);
		return (0);
	}
	ft_fork(path, cmd);
	return (0);
}

int	check_for_var(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
		{
			put_data_var(line);
			put_data_exp(line);
			return (0);
		}
		i++;
	}
	if (protectline(line))
		pathfinder(line);
	else
		printf("bash: %s: command not found\n", line);
	return (0);
}
