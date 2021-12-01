/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:09:35 by sungslee          #+#    #+#             */
/*   Updated: 2021/12/01 17:14:33 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cmd_exit(t_command *command)
{
	close_fd_and_pipes();
	set_res(0);
	if (command->arg_list)
	{
		if (command->arg_list[0][0] != '-'
			&& !ft_is_number(command->arg_list[0]))
		{
			error_builtin("exit", command->arg_list[0], NUMERIC_REQUIRED);
			set_res(255);
		}
		else if (ft_len_doublestr(command->arg_list) > 1)
			return (error_builtin("exit", "\b\b", TOO_MANY_ARG));
		else if (ft_strlen(command->arg_list[0]) >= 20)
		{
			error_builtin("exit", command->arg_list[0], NUMERIC_REQUIRED);
			set_res(255);
		}
		else
		{
			ft_putendl_fd("exit", 1);
			set_res(ft_atoll(command->arg_list[0]));
		}
	}
	exit(g_res);
	return ;
}
