/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:35:24 by sungslee          #+#    #+#             */
/*   Updated: 2020/11/02 17:41:10 by yshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\b\b  \b\b\n");
		ft_putstr("catshell$ ");
		set_res(1);
	}
	if (signo == SIGQUIT)
		ft_putstr("\b\b  \b\b");
}

void		sig_execve_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		set_res(130);
		signal(SIGINT, (void *)sig_handler);
	}
	else if (signo == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", 2);
		set_res(131);
		signal(SIGQUIT, (void *)sig_handler);
	}
}
