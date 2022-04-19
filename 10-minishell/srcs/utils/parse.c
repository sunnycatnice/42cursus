/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:23:06 by bde-luca          #+#    #+#             */
/*   Updated: 2022/04/19 15:13:36 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_token_error(char *input)
{
	int	i;
	int	pipe;
	int	red;

	i = -1;
	pipe = 0;
	red = 0;
	while (input[++i])
	{
		if (input[i] == '>' || input[i] == '<' || input[i] == '|')
		{
			if (!(check_token(input[i], input[i + 1])))
				return (-1);
			if (input[i] == '|')
				pipe++;
			if (input[i] == '>' || input[i] == '<')
				red++;
		}
	}
	if (pipe > 0)
		return (0);
	if (red > 0)
		return (-2);
	return (2);
}

int	check_echo(char *line, int checker)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_substr(line, 4, ft_strlen(line) - 4);
	while (tmp[i])
	{
		if (tmp[i] == '"' || tmp[i] == 047)
		{
			free(tmp);
			return (1);
		}
		i++;
	}
	free(tmp);
	return (checker);
}

void	sort_things(char *input)
{
	int	checker;

	g_sh.in_pipe = 0;
	checker = check_token_error(input);
	if (!(ft_strncmp(input, "echo", 4)))
		checker = check_echo(input, checker);
	if (!(checker))
		has_pipesandred(input);
	else if (checker == -2)
		is_a_red(input);
	else if (checker > 0)
	{
		g_sh.av = ft_split_and_count(g_sh.line, ' ');
		ft_exec_cmd();
		free_matrix(g_sh.av);
	}
}

int	all_spaces(char *line)
{
	int	i;
	int	space;

	space = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == 32 || line[i] == 9)
			space++;
		i++;
	}
	if (i == space)
		return (0);
	return (1);
}

char	*read_line(void)
{
	char	*input;

	g_sh.pipe.g_res = 0;
	ft_init();
	ft_putstr_fd("", 1);
	input = readline("\033[0;37m<<aS\033[1;91mHell\033[0ma>>  ");
	if (input == NULL)
		ft_putstr_fd("exit\n", 1);
	ft_check_for_d(input);
	if (!(ft_strlen(input)) || !(all_spaces(input)))
		return (input);
	input = ft_strtrim(input, " ");
	add_history(input);
	if (input[0] == '"' || input[0] == '\'')
		if (check_unclosed_quotes(input))
			return (input);
	finish_read_line(input);
	sort_things(g_sh.line);
	if (g_sh.line)
		free(g_sh.line);
	return ("ok");
}
