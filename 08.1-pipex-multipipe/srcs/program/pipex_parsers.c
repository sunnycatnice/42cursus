/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:11:08 by ecarciof          #+#    #+#             */
/*   Updated: 2021/11/24 19:13:45 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

char	**path_setter(char **cmd)
{
	char	**path_list;

	path_list = malloc(sizeof(char **) * 6);
	path_list[0] = ft_strjoin("/usr/local/bin/", cmd[0]);
	path_list[1] = ft_strjoin("/usr/bin/", cmd[0]);
	path_list[2] = ft_strjoin("/bin/", cmd[0]);
	path_list[3] = ft_strjoin("/usr/sbin/", cmd[0]);
	path_list[4] = ft_strjoin("/usr/local/munki/", cmd[0]);
	path_list[5] = NULL;
	return (path_list);
}

void	ft_pathchecker(char **argv, t_var bonus)
{
	char	**path_list;
	char	**cmd;
	int		i;

	i = -1;
	cmd = ft_split(argv[2 + bonus.id + bonus.f_limiter]);
	path_list = path_setter(cmd);
	while (path_list[++i])
	{
		if (access(path_list[i], X_OK) == 0)
		{
			ft_free_mat(path_list);
			ft_free_mat(cmd);
			return ;
		}
	}
	ft_error_command(cmd, NULL);
}

char	*ft_pathfinder(char **cmd)
{
	char	**path_list;
	char	*path;
	int		i;

	i = -1;
	path = NULL;
	path_list = path_setter(cmd);
	while (path_list[++i])
	{
		if (access(path_list[i], X_OK) == 0)
		{
			path = ft_strdup(path_list[i]);
			ft_free_mat(path_list);
			return (path);
		}
	}
	ft_free_mat(path_list);
	ft_error_command(cmd, path);
	return (NULL);
}

char	*ft_gnl(void)
{
	int		dim;
	char	*temp;
	char	*buff;

	dim = 1;
	buff = NULL;
	temp = ft_calloc(sizeof(char), 2);
	if (!buff)
		buff = ft_calloc(sizeof(char), 1);
	while (dim > 0)
	{
		dim = read(0, temp, 1);
		if (dim == -1)
		{
			free(buff);
			free(temp);
			return (NULL);
		}
		temp[dim] = '\0';
		if (temp[0] == 10)
			dim = 0;
		buff = ft_strjoin(buff, temp);
	}
	free(temp);
	return (buff);
}
