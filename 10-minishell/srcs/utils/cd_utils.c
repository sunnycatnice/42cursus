/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vceccaro <vceccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:51:28 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/22 19:33:31 by vceccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*double_quotes(char *line)
{
	int		i;
	int		j;

	i = 1;
	if (line[1] == '"')
		i = 2;
	j = i;
	while (line [j])
	{
		if (line[j + 1] == '"')
			break ;
		j++;
	}
	if (line[j] == 0)
		return (line);
	line = ft_substr(line, i, j + 1 - i);
	return (line);
}

char	*single_quote(char *line)
{
	int		i;
	char	*ret;

	i = 1;
	while (line[i] != 047)
		i++;
	ret = ft_substr(line, 1, i - 1);
	return (ret);
}

char	*extract_quotes(char *path)
{
	if (path[0] == '"')
		path = ft_strtrim(path, "\"");
	else if (path[0] == 047)
		path = ft_strtrim(path, "'");
	else if (path[0] == '$')
		path = get_path(path);
	return (path);
}

void	put_in_env(char *old, char *new)
{
	t_node	*p;

	p = *g_sh.node;
	if (p)
	{
		while (p)
		{
			if (!(ft_strncmp(p->name, "PWD=", ft_strlen(p->name))))
				break ;
			p = p->next;
		}
		if (!(ft_strncmp(p->name, "PWD=", ft_strlen(p->name))))
		{
			free(p->string);
			p->string = ft_strdup(new);
			if (p->next != NULL)
				p = p->next;
			if (!(ft_strncmp(p->name, "OLDPWD=", ft_strlen(p->name))))
			{
				free(p->string);
				p->string = ft_strdup(old);
			}
		}
	}
}

char	*get_cdline(char *line)
{
	int		i;
	int		j;

	if (line[0] == 'c')
		i = 2;
	else
		i = 1;
	while (line[i] == ' ')
		i++;
	if (line[i] != '~')
	{
		j = i + 1;
		while (line[j] != 0)
		{
			if (line[j] == ' ')
				break ;
			j++;
		}
	}
	line = ft_substr(line, i, ft_strlen(line) - i);
	if (line[0] == '"')
		line = double_quotes(line);
	return (line);
}
