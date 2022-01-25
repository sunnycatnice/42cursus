/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:51:18 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_i(char *line, char split, int i, int n)
{
	while (line[i])
	{
		if (line[i] == split)
			n++;
		i++;
	}
	return (i);
}

char	*envp_filler(t_node *envp, char *path_line)
{
	while (envp->next != NULL)
	{
		if (!(ft_strncmp(envp->name, "PATH", 4)))
			return (path_line = envp->string);
		envp = envp->next;
	}
	path_line = "error";
	return (path_line);
}

int	do_the_while(char **paths, int i)
{
	i = 0;
	while (paths[i])
		i++;
	return (i);
}

char	*finish_pipepath(int i, char *cmd, char **paths)
{
	int		j;
	char	*path;
	char	*tmp;
	char	*tmp2;

	j = 0;
	path = "error";
	while (j++ < i)
	{
		tmp = ft_strjoin(paths[j], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!(access(tmp2, X_OK)))
		{
			path = ft_strdup(tmp2);
			free_matrix(paths);
			free(tmp2);
			return (path);
		}
		free(tmp2);
	}
	free_matrix(paths);
	return (path);
}

char	*get_pipepath(char *cmd)
{
	char	**paths;
	char	*path_line;
	int		i;
	int		j;

	path_line = NULL;
	i = 0;
	path_line = envp_filler(*g_sh.node, path_line);
	if (!(ft_strncmp(path_line, "error", 5)))
		if ((printf("bash: %s: no such file or directory\n", cmd)) > 0)
			return ("error2");
	paths = ft_bnessi_split(path_line, ':');
	i = do_the_while(paths, i);
	path_line = finish_pipepath(i, cmd, paths);
	j = 0;
	return (path_line);
}
