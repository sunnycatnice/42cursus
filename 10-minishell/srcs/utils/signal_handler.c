/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:49:23 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_check_for_d(char *line)
{
	int	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if ((int)line[i] == EOF)
		{
			return ;
		}
		i++;
	}
}

void	ft_signals(void)
{
	g_sh.t_sa.sa_handler = handler;
	g_sh.t_sa2.sa_handler = SIG_IGN;
	sigaction(SIGINT, &g_sh.t_sa, NULL);
	sigaction(SIGQUIT, &g_sh.t_sa2, NULL);
}
