/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:10:57 by ecarciof          #+#    #+#             */
/*   Updated: 2021/11/24 19:13:45 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	ft_arg_checker(int argc, char **argv)
{
	int	fd;

	if (argc < 5)
		ft_error_arg();
	if (ft_strncmp(argv[1], "here_doc", ft_max(ft_strlen(argv[1]), 8)) == 0)
	{
		if (argc < 6)
			ft_error_arg();
		fd = 0;
	}
	else
	{
		fd = open(argv[1], O_RDONLY, 0666);
		if (fd == -1)
			ft_error_permission();
		close(fd);
	}
}

void	ft_middleman(char **argv, int *fd, char **envp, t_var bonus)
{
	int		outer;
	int		inner;
	char	**cmd;
	char	*path;

	outer = (bonus.id * 2) + 1;
	inner = (bonus.id - 1) * 2;
	ft_close(bonus, fd);
	dup2(fd[outer], 1);
	dup2(fd[inner], 0);
	close(fd[outer]);
	close(fd[inner]);
	cmd = ft_split(argv[2 + bonus.f_limiter + bonus.id]);
	path = ft_pathfinder(cmd);
	execve(path, cmd, envp);
	ft_error_command(cmd, path);
}

void	ft_son(char **argv, int *fd, char **envp, t_var bonus)
{
	int		in;
	char	**cmd;
	char	*path;
	char	*temp;

	in = 0;
	temp = NULL;
	path = NULL;
	if (bonus.f_limiter == 1)
		ft_limiter(in, temp, path, bonus);
	if (bonus.f_limiter == 1)
		in = open("input", O_RDONLY, 0666);
	else
		in = open(argv[1], O_RDONLY, 0666);
	if (in == -1)
		ft_error_permission();
	ft_close(bonus, fd);
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	dup2(in, 0);
	cmd = ft_split(argv[2 + bonus.f_limiter]);
	path = ft_pathfinder(cmd);
	execve(path, cmd, envp);
	ft_error_command(cmd, path);
}

void	ft_father(char **argv, int *fd, char **envp, t_var bonus)
{
	int		out;
	char	**cmd;
	char	*path;
	int		inner;

	if (bonus.f_limiter == 1)
		out = open(argv[3 + bonus.f_limiter + bonus.pipes], \
		O_RDWR | O_CREAT | O_APPEND, 0666);
	else
		out = open(argv[3 + bonus.f_limiter + bonus.pipes], \
		O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (out == -1)
		ft_error_permission();
	inner = (bonus.id - 1) * 2;
	ft_close(bonus, fd);
	dup2(fd[inner], 0);
	close(fd[inner]);
	dup2(out, 1);
	cmd = ft_split(argv[2 + bonus.f_limiter + bonus.pipes]);
	path = ft_pathfinder(cmd);
	execve(path, cmd, envp);
	ft_error_command(cmd, path);
}

int	main(int argc, char **argv, char *envp[])
{
	int		*fd;
	int		i;
	t_var	bonus;

	bonus.f_limiter = 0;
	bonus.limiter = NULL;
	ft_arg_checker(argc, argv);
	if (ft_strncmp(argv[1], "here_doc", ft_max(ft_strlen(argv[1]), 8)) == 0)
		bonus.f_limiter = 1;
	if (bonus.f_limiter == 1)
		bonus.limiter = ft_strdup(argv[2]);
	bonus.pipes = argc - 4 - bonus.f_limiter;
	fd = malloc(sizeof(int) * (2 * bonus.pipes));
	ft_pipeline(argv, fd, envp, bonus);
	i = -1;
	while (++i < 2 * bonus.pipes)
		close(fd[i]);
	free(fd);
	return (0);
}
