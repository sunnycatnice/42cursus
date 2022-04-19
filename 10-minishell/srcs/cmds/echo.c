/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vceccaro <vceccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:21:14 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/21 20:48:30 by vceccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	finish_echo_print(char *output, char end, int fd)
{
	char	*last_out;

	if (!(ft_strncmp(output, "$?", 2)))
	{
		last_out = ft_itoa(g_sh.last_output);
		write(fd, last_out, ft_strlen(last_out));
		if (ft_strlen(output) > 2)
		{
			output = ft_substr(output, 2, ft_strlen(output) - 2);
			write(fd, &output, ft_strlen(output));
			write(fd, &end, 1);
			free(output);
			return ;
		}
		write(fd, "\n", 1);
	}
	else
	{
		if (output[0] == 047)
			output = ft_substr(output, 1, ft_strlen(output) - 2);
		write(fd, output, ft_strlen(output));
		write(fd, &end, 1);
	}
}

void	do_print(int n, char *output, int fd)
{
	int		i;
	char	end;
	char	*ret;

	i = 0;
	end = '\n';
	ret = 0;
	if (n != 0)
	{
		if (!(output[i]))
			return ;
		end = '\0';
	}
	if ((output[0] == 047) && (output[1] != '$'))
		output = ft_substr(output, 1, ft_strlen(output) - 2);
	if (output[0] == '$' && (output[1] != '?'))
	{
		ret = get_echo(ft_substr(output, 1, ft_strlen(output) - 1));
		write(fd, ret, ft_strlen(ret));
		write(fd, &end, 1);
		return ;
	}
	finish_echo_print(output, end, fd);
}

void	continue_echo(char *line, int i, int n, int fd)
{
	int		j;
	char	*output;

	j = 0;
	while ((line[i] == ' ') || (line[i] == 34))
		i++;
	while (line[j])
		j++;
	if (line[j - 1] == 34)
		output = ft_substr(line, i, ft_strlen(line) - i - 1);
	else
		output = ft_substr(line, i, ft_strlen(line) - i);
	do_print(n, output, fd);
	free(output);
}

int	get_fd(void)
{
	int		fd;
	t_red	*red;

	red = NULL;
	if (*g_sh.red != NULL)
		red = *g_sh.red;
	if (red != NULL)
		fd = red->fd;
	else
		fd = 1;
	return (fd);
}

int	ft_echo(char *line)
{
	int		i;
	int		n;
	int		fd;

	if (!(ft_strncmp(line, "echo", 4)) && (ft_strlen(line) == 4))
		return (printf("\n"));
	i = get_i(line);
	fd = get_fd();
	n = 0;
	while (line[i] == ' ')
		i++;
	if ((line[i] == '-') && (line[i + 1] == 'n'))
	{
		i = i + 2;
		if (line[i] != ' ' && line[i] != 0)
		{
			printf("bash: %s: command not found\n", line);
			return (1);
		}
		n = 1;
		i = ft_echo_helper(line, i);
	}
	continue_echo(line, i, n, fd);
	return (0);
}
