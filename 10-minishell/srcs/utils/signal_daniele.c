/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_daniele.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 03:26:59 by dmangola          #+#    #+#             */
/*   Updated: 2022/01/22 06:08:27 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_prompt(void)
{
	ft_putstr_fd("\033[0;37m  <<aS\033[1;91mHell\033[0ma>>  ", 1);
}

void	handle_signal(int signo)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	if (signo == SIGINT)
	{
		if (pid == -1)
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		else
			ft_putchar_fd('\n', STDOUT);
	}
}

void	set_signal(void)
{
	g_sh.t_sa2.sa_handler = SIG_IGN;
	signal(SIGINT, handle_signal);
	sigaction(SIGQUIT, &g_sh.t_sa2, NULL);
}
