/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:11:57 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/14 21:44:28 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_start_msg(void)
{
	printf("\033[0;37m\n");
	printf("                           _.-''|''-._              \n");
	printf("                        .-'     |     `-.           \n");
	printf("                      .'\\       |       /`.        \n");
	printf("                    .'   \\      |      /   `.       \n");
	printf("                    \\     \\     |     /     /      \n");
	printf("                     `\\    \\    |    /    /'       ╔╗\n");
	printf("         ╔═╗           `\\   \\   |   /   /'         ║║ \n");
	printf("         ║ ║ ╔╗ ╔══╗      `\\ \\  |  /  /'     ╔══╗  ║║ \n");
	printf("         ║ ║ ╚╝ ║╔╗║    ._.-`\\\\ | / /'-._    ║╔╗║  ╚╝ \n");
	printf("         ║ ╚═╗  ║╔╗║   {______`\\|/'______}   ║╔╗║  ╔╗\n");
	printf("         ╚═══╝  ╚╝╚╝           `-'           ╚╝╚╝  ╚╝\n\n");
	printf("\033[0;32m");
	printf("            SHell powered by bde-luca && dmangola \n\n");
	printf("\033[0m");
}

void	ft_redirect_output_append(void)
{
	g_sh.files.saved_stdout = dup(1);
	g_sh.files.fd_file2 = open(g_sh.files.fileout, O_RDWR | O_APPEND);
	dup2(g_sh.files.fd_file2, 1);
	close(g_sh.files.fd_file2);
	close(g_sh.files.saved_stdout);
}

void	ft_redirect_input(void)
{
	g_sh.files.saved_stdin = dup(0);
	g_sh.files.fd_file1 = open(g_sh.files.filein, O_RDWR);
	dup2(g_sh.files.fd_file1, 0);
}

void	ft_check_in_out(void)
{
	ft_save_standard_fd();
	if (g_sh.checkif.input_file && (g_sh.cmds.idx == 0))
		ft_redirect_input();
	if (g_sh.checkif.output_file && (g_sh.cmds.idx == g_sh.pipe.pipe_nbr))
		ft_redirect_output();
	else if (g_sh.checkif.append_file)
		ft_redirect_output_append();
}
