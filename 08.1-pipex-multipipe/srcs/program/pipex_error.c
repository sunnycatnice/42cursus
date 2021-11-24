/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:11:12 by ecarciof          #+#    #+#             */
/*   Updated: 2021/11/24 19:27:43 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	ft_error_arg(void)
{
	write (2, "Error: Arguments invalid\n", 25);
	exit(0);
}

void	ft_error_pipe(int *fd)
{
	free(fd);
	write (2, "Error: Pipe broken\n", 19);
	exit(0);
}

void	ft_error_fork(void)
{
	write (2, "Error: Fork failed\n", 19);
	exit(0);
}

void	ft_error_command(char **cmd, char *path)
{
	write (2, "Error: Command not found\n", 25);
	ft_free(cmd, path);
}

void	ft_error_permission(void)
{
	write (2, "Error: Can't access file or it doesn't exist\n", 45);
	exit(0);
}
