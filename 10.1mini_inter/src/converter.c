/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:55:22 by sungslee          #+#    #+#             */
/*   Updated: 2020/11/03 00:32:21 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		convert_res(char **ret, char *str, int *i, int first)
{
	char	*val;
	int		j;

	val = (first) ? ft_itoa(g_res) : ft_strdup("0");
	j = (str[*i + 1] == '{') ? *i + 3 : *i + 1;
	*i = 0;
	while (val && val[*i])
		ft_realloc(ret, val[(*i)++]);
	*i = j;
	ft_free_str(&val);
	return ;
}

static	void	convert_env(char **ret, char *s, int *i, int first)
{
	char	*name;
	char	*val;
	t_bool	bracket;
	int		j;
	char	end;

	if (s[*i + 1] == '?' || (s[*i + 1] == '{' && s[*i + 2] == '?'))
		return (convert_res(ret, s, i, first));
	j = *i + 1;
	if (!s[j])
		return ;
	bracket = (s[j] == '{') ? TRUE : FALSE;
	j += (bracket) ? 1 : 0;
	end = (bracket) ? '}' : ' ';
	name = 0;
	while (s[j] && s[j] != end && !ft_is_set(s[j], "\'\":="))
		ft_realloc(&name, s[j++]);
	if (!s[j] || end == ' ')
		j--;
	val = find_value(name);
	*i = 0;
	while (val && val[*i])
		ft_realloc(ret, val[(*i)++]);
	ft_free_str(&name);
	*i = j;
}

static void		convert(char **src, int first)
{
	int		i;
	int		opened;
	char	*str;
	char	*ret;

	i = 0;
	opened = 0;
	str = *src;
	if (!(ret = (char *)ft_calloc(sizeof(char), 1)))
		return ;
	while (str[i])
	{
		if (open_handle(&opened, str[i]))
			;
		else if (opened != '\'' && str[i] == '$' \
			&& str[i + 1] && !ft_is_set(str[i + 1], " \'\""))
			convert_env(&ret, str, &i, first);
		else if (str[i] < 0)
			ft_realloc(&ret, str[i] * -1);
		else
			ft_realloc(&ret, str[i]);
		i++;
	}
	ft_free_str(&str);
	*src = ret;
}

static	void	convert_job(t_job *job, int first)
{
	int		i;
	t_redir	*redir;

	if (job->command.cmd)
		convert(&job->command.cmd, first);
	i = 0;
	if (job->command.arg_list)
		while (job->command.arg_list[i])
			convert(&job->command.arg_list[i++], first);
	if (!job->redir_list)
		return ;
	redir = job->redir_list;
	while (redir)
	{
		if (redir->sign)
			convert(&redir->sign, first);
		if (redir->arg)
			convert(&redir->arg, first);
		redir = redir->next;
	}
}

void			converter(t_table *table)
{
	t_job	*job;
	int		first;

	first = TRUE;
	job = table->job_list;
	while (job)
	{
		convert_job(job, first);
		job = job->next;
		first = FALSE;
	}
	return ;
}
