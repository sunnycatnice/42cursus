/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollaro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:20:47 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_env(char	*name)
{
	t_node	*node;
	char	*content;

	node = *g_sh.node;
	content = 0;
	if (node)
	{
		while (node)
		{
			if (!(ft_strncmp(name, node->name, ft_strlen(name))))
			{
				content = ft_strdup((char *)node->string);
				if (content[0] == '/')
					printf("bash: %s: is a directory\n",
						(char *)node->string);
				else
					printf("bash: %s: command not found\n",
						(char *)node->string);
				free(content);
				return (1);
			}		
			node = node->next;
		}
	}
	return (0);
}

void	do_dollar(char *name)
{
	t_node	*var;
	char	*str;

	var = *g_sh.var;
	str = 0;
	if (var)
	{
		while (var)
		{
			if (!(ft_strncmp(var->name, name, ft_strlen(name))))
			{
				if (var->string != NULL)
				{
					str = ft_strdup((char *)var->string);
					do_cmd(str);
					free(str);
					free(name);
				}
				return ;
			}
			var = var->next;
		}
	}
	free(name);
}

void	ft_d_helper(char *to_save, char *name)
{
	if (!(check_env(to_save)))
	{
		name = ft_substr(name, 1, ft_strlen(name) - 1);
		ft_lstadd_back(g_sh.var, name);
		do_dollar(to_save);
	}
}

int	ft_dollaro(char *name)
{
	int		i;
	int		j;
	char	*to_save;

	i = 1;
	j = 0;
	if (name[0] == 047)
		if ((printf("bash: %s: command not found\n",
					ft_substr(name, 1, ft_strlen(name) - 2))))
			return (1);
	if (!(ft_strncmp(name, "$?", 2)))
		if (printf("bash: %d: command not found\n", g_sh.last_output))
			return (1);
	while (name[j++])
	{
		if (name[j] == '=' || name[j] == '"')
			if ((printf("command not found\n")) != 0)
				return (1);
	}
	to_save = ft_substr(name, i, j - i);
	ft_d_helper(to_save, name);
	free(name);
	return (0);
}
