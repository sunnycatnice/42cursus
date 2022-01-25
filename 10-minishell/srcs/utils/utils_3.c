/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:27:35 by dmangola          #+#    #+#             */
/*   Updated: 2022/01/14 21:29:09 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_append(char *s1, char *s2, char glue)
{
	int	i;
	int	j;

	if (ft_strlen(s1) == 0)
		return (0);
	i = ft_strlen(s1);
	j = 0;
	if (glue != 0)
	{
		s1[i] = glue;
		i++;
	}
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

char	**get_env(void)
{
	char	**matrix;
	t_node	*node;
	int		i;

	i = 0;
	node = *g_sh.node;
	matrix = malloc(sizeof(char **));
	while (node)
	{
		matrix[i] = malloc(ft_strlen(node->name) + ft_strlen(node->string) + 1);
		matrix[i] = ft_strjoin(node->name, node->string);
		node = node->next;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

char	**get_cmd(char *line)
{
	char	**matrix;
	int		i;

	matrix = ft_bnessi_split(line, ' ');
	i = 0;
	while (matrix[i])
	{
		matrix[i] = ft_strtrim(matrix[i], " ");
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

void	parse_line(void)
{	
	if (g_sh.av[0] == (void *)0)
		return ;
	ft_exec_cmd();
	free(g_sh.cmds.path_cmd);
}

int	check_token(char first, char second)
{
	if ((first == '|' && (second == '|'))
		|| ((first == '>' && (second != ' '
					&& (second != '>' && (!(ft_is_alpha(second)))))))
		|| (first == '<' && (second != ' '
				&& (second != '<' && (!(ft_is_alpha(second)))))))
	{
		printf("bash: syntax error near unexpected token '%c'\n", second);
		return (0);
	}
	return (1);
}
