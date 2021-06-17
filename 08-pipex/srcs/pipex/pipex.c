/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:52:13 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/12 17:15:46 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minilibft.h"

void	check_args(int ac, char **av)
{
	if (ac != 5)
	{
		ft_putstr_fd("Correct syntax: ./pipex inputfile cmd1 cmd2 outputfile \
				\n", 2);
	}
}

int	main(int ac, char **av, char **envp)
{
	pid_t	pid;

	check_args(ac, av);
	if (pipe(p) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Fork failed\n", 2);
		return (0);
	}
	if (pid == 0)
		call_child(p, av, envp);
	else
		call_father(p, av, envp);
	return (0);
}
