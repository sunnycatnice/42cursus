/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:41:24 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_other(char one, char two, t_red *red, int i)
{
	if (one == '<')
	{
		if (i == '<')
			red->start = 1;
		if (two == '<')
			red->token = "<<";
		else
			red->token = "<";
		return (0);
	}
	return (1);
}

void	get_token(t_red *red, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '>')
		{
			if (line[0] == '>')
				red->start = 1;
			if (line[i + 1] == '>')
				red->token = ">>";
			else
				red->token = ">";
			return ;
		}
		if (!(check_other(line[i], line[i + 1], red, i)))
			return ;
		i++;
	}
}

void	sort_start_red(t_red *red, char *input)
{
	int		i;
	char	**matrix;
	char	*cmd;

	i = 0;
	cmd = malloc(sizeof(char *));
	while (input[i] == red->token[0])
		i++;
	input = ft_space_remove(input);
	matrix = ft_bnessi_split(input, ' ');
	i = 0;
	red->filename = ft_strtrim(matrix[1], " ");
	i = 2;
	while (matrix[i])
	{
		cmd = ft_append(cmd, matrix[i], ' ');
		i++;
	}
	red->cmd = ft_strtrim(cmd, " ");
}

t_red	*init_red(char *input)
{
	char	**matrix;
	t_red	*red;
	char	*tmp;

	red = malloc(sizeof(t_red));
	red->start = 0;
	get_token(red, input);
	matrix = ft_bnessi_split(input, red->token[0]);
	tmp = malloc(sizeof(ft_strlen(matrix[0]) + 1));
	tmp = ft_strtrim(matrix[0], " ");
	red->cmd = ft_strdup(tmp);
	if (red->cmd[0] == '/')
		red->cmd = ft_checkif_path(red->cmd);
	tmp = malloc(sizeof(ft_strlen(matrix[1]) + 1));
	tmp = ft_strtrim(matrix[1], " ");
	red->filename = ft_strdup(tmp);
	red->fd = 0;
	red->ret = 0;
	red->next = NULL;
	red->prev = NULL;
	return (red);
}

void	is_a_red(char *input)
{
	t_red	*red;

	red = init_red(input);
	if (red->token[0] == '>')
		right_token(red);
	else if (red->token[0] == '<')
		left_token(red);
}
