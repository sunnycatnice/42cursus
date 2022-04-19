/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:55:49 by bde-luca          #+#    #+#             */
/*   Updated: 2022/04/19 15:16:00 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_cmd(void)
{
	char	*word;
	int		result;
	int		i;

	i = 0;
	word = g_sh.av[i];
	word = ft_checkif_path(word);
	result = exec_recoded_cmds(i);
	if (result == 1)
		return (1);
	return (0);
}

void	set_res(long long int res)
{
	g_sh.pipe.g_res = res;
	return ;
}

int	exec_recoded_cmds(int i)
{
	if (!(ft_strncmp(g_sh.av[i], "pwd", 3)))
		return (g_sh.last_output = ft_pwd());
	else if (!(ft_strncmp(g_sh.av[i], "echo", 4)))
		return (g_sh.last_output = ft_echo(g_sh.line));
	else if (!(ft_strncmp(g_sh.av[i], "cd", 2)))
		return (g_sh.last_output = ft_cd(g_sh.line));
	else if (!(ft_strncmp(g_sh.av[i], "env", 3)))
		return (g_sh.last_output = ft_env(1));
	else if (!(ft_strncmp(g_sh.av[i], "export", 6)))
		return (g_sh.last_output = ft_export(g_sh.line));
	else if (!(ft_strncmp(g_sh.av[i], "$", 1))
		|| !(ft_strncmp(g_sh.av[i], "'$", 2)))
		return (g_sh.last_output = ft_dollaro(g_sh.line));
	else if (!(ft_strncmp(g_sh.av[i], "unset", 5)))
		return (g_sh.last_output = ft_unset(g_sh.line));
	else if (!(ft_strncmp(g_sh.av[i], "exit", 4)))
		return (g_sh.last_output = ft_exit());
	else
		(g_sh.last_output = check_for_var(g_sh.line));
	return (-1);
}
