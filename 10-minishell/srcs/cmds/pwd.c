/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:25:27 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	finish_pwd(char *cwd)
{
	t_node	*p;

	p = *g_sh.node;
	if (p)
	{
		while (p)
		{
			if (!(ft_strncmp(p->name, "OLDPWD=", ft_strlen(p->name))))
				break ;
			p = p->next;
		}
		if (!(ft_strncmp(p->name, "OLDPWD", ft_strlen(p->name))))
			p->string = ft_strdup(cwd);
	}
}

int	ft_pwd(void)
{
	t_red	*red;
	char	cwd[1024];
	int		fd;

	getcwd(cwd, sizeof(cwd));
	red = NULL;
	if (*g_sh.red != NULL)
		red = *g_sh.red;
	if (g_sh.standard_out != 0)
		fd = g_sh.standard_out;
	if (red != NULL)
		fd = red->fd;
	else
		fd = 1;
	write(fd, cwd, ft_strlen(cwd));
	write(fd, "\n", 1);
	finish_pwd(cwd);
	return (0);
}
