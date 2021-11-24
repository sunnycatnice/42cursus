/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:11:03 by ecarciof          #+#    #+#             */
/*   Updated: 2021/11/24 19:13:45 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	ft_free_mat(char **mat)
{
	int	i;

	i = -1;
	while (mat[++i])
		free(mat[i]);
	if (mat)
		free(mat);
}

void	ft_free(char **cmd, char *path)
{
	ft_free_mat(cmd);
	if (path)
		free(path);
	exit(0);
}

void	ft_close(t_var bonus, int *fd)
{
	int	outer;
	int	inner;
	int	i;

	i = -1;
	outer = (bonus.id * 2) + 1;
	inner = (bonus.id - 1) * 2;
	while (++i < bonus.pipes * 2)
		if (i != outer && i != inner)
			close(fd[i]);
}

void	ft_limiter(int in, char *temp, char *path, t_var bonus)
{
	int	f_while;

	in = open("input", O_RDWR | O_CREAT | O_TRUNC, 0666);
	f_while = 1;
	temp = ft_strjoin(bonus.limiter, "\n");
	while (f_while)
	{
		path = ft_gnl();
		if (ft_strncmp(path, temp, \
		ft_max(ft_strlen(path), ft_strlen(temp))) == 0)
			f_while = 0;
		else
			write(in, path, ft_strlen(path));
		free(path);
	}
	free(temp);
	close(in);
}

void	ft_pipeline(char **argv, int *fd, char **envp, t_var bonus)
{
	int	pid;
	int	i;

	i = 0;
	while (i <= bonus.pipes)
	{
		bonus.id = i;
		if (i != bonus.pipes)
		{
			if (pipe(&fd[i * 2]) < 0)
				ft_error_pipe(fd);
		}
		if (i != bonus.pipes)
			pid = fork();
		if (pid == -1)
			ft_error_fork();
		if (pid == 0 && i == 0)
			ft_son(argv, fd, envp, bonus);
		else if (i == bonus.pipes)
			ft_father(argv, fd, envp, bonus);
		else if (pid == 0 && i != 0)
			ft_middleman(argv, fd, envp, bonus);
		i++;
	}
}
