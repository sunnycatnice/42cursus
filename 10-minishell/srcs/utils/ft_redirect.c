/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:14:47 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/18 21:14:50 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_save_standard_fd(void)
{
	g_sh.files.saved_stdin = dup(0);
	g_sh.files.saved_stdout = dup(1);
}

void	restore_standard_fd(void)
{
	dup2(g_sh.files.saved_stdin, 0);
	dup2(g_sh.files.saved_stdout, 1);
	close(g_sh.files.saved_stdin);
	close(g_sh.files.saved_stdout);
}

void	ft_redirect_output(void)
{
	g_sh.files.saved_stdout = dup(1);
	g_sh.files.fd_file2 = open(g_sh.files.fileout, O_RDWR | O_TRUNC);
	dup2(g_sh.files.fd_file2, 1);
}
