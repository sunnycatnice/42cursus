/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:36:50 by sungslee          #+#    #+#             */
/*   Updated: 2021/12/01 17:14:38 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		cmd_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 1024);
	if (!path)
		return (error_builtin("env", "", FAIL_TO_GET_PATH));
	ft_putstr_fd(path, 1);
	ft_putchar_fd('\n', 1);
	ft_free_str(&path);
	return (set_res(0));
}
