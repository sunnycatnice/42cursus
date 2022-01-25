/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:20:21 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	squiggly(char *path)
{
	if (path[0] == '~' || !(path[0]))
	{
		if ((path[1] != ' ') && (path[1] != 0) && (path[1] != '/'))
			ft_print_cderror(ft_substr(path, 1, ft_strlen(path) - 1));
		else
			return (mini_squig(path, 1));
	}
	if (path[0] == '"' || path[0] == 047)
		return (-2);
	return (-1);
}

char	*get_path(char *path)
{
	t_node	*node;

	node = *g_sh.node;
	path = ft_substr(path, 1, ft_strlen(path) - 1);
	while (node)
	{
		if (!(ft_strncmp(path, node->name, ft_strlen(path))))
		{
			path = ft_strdup((char *)node->string);
			if ((ft_strlen(path) > ft_strlen(g_sh.pwd))
				&& (path[0] == g_sh.pwd[0]))
				path = ft_substr(path, ft_strlen(g_sh.pwd) + 1,
						ft_strlen(path) - ft_strlen(g_sh.pwd));
		}
		node = node->next;
	}
	return (path);
}

int	move_dir(char *path, int sent)
{
	char	*oldpath;

	oldpath = 0;
	oldpath = getcwd(oldpath, sizeof(oldpath));
	g_sh.firstoldpwd = 0;
	getcwd(g_sh.oldpwd, sizeof(g_sh.oldpwd));
	if (sent == 0 && ((chdir((path))) == -1))
	{
		printf("cd: no such file or directory: %s\n", path);
		return (1);
	}
	getcwd(g_sh.pwd, sizeof(g_sh.pwd));
	put_in_env(g_sh.oldpwd, g_sh.pwd);
	free(oldpath);
	return (0);
}

int	do_cd(int squig, char *path)
{
	int	sent;

	sent = 0;
	if (squig == -2)
		path = extract_quotes(path);
	else if (squig == 1)
	{
		if (!(chdir(getenv("HOME"))))
			sent = 1;
		if (path[0] == '~')
		{
			printf("~");
			ft_pwd();
		}
	}
	else if (squig == 2)
	{
		path = get_cdline(ft_substr(path, 1, ft_strlen(path) - 1));
		printf("~/%s\n", path);
	}
	if (move_dir(path, sent) > 0)
		return (1);
	return (0);
}

int	ft_cd(char *line)
{
	char	*path;
	int		squig;

	if (!(ft_strncmp(line, "cd '.'", 6)))
		return (0);
	path = get_cdline(line);
	squig = squiggly(path);
	if (squig != 0)
	{
		if (do_cd(squig, path) > 0)
		{
			free(path);
			return (1);
		}
	}
	free(path);
	return (0);
}
