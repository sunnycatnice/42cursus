/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:28:55 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minishell_loop(void)
{
	char	*line;
	int		status;

	status = 1;
	while (status)
	{
		set_signal();
		line = read_line();
		if (!line)
			break ;
	}
}

t_node	*get_new(char *line, int i)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->name = ft_substr(line, 0, i);
	new->string = ft_substr(line, i, ft_strlen(line) - i);
	new->next = NULL;
	return (new);
}

void	save_envp(char *line, t_node **lst)
{
	int		i;
	t_node	*new;

	i = 0;
	while (line[i] != '=')
		i++;
	i++;
	new = get_new(line, i);
	ft_lstaddnode_back(lst, new);
}

int	main(int argc, char **argv, char **envp)
{
	int		ac;
	char	**av;
	int		i;
	t_node	*lst;

	i = -1;
	ac = argc;
	av = argv;
	lst = 0;
	g_sh.standard_out = 1;
	g_sh.standard_in = 0;
	ft_print_start_msg();
	g_sh.var = malloc(sizeof(t_node));
	*g_sh.var = NULL;
	g_sh.exp = malloc(sizeof(t_node));
	*g_sh.exp = NULL;
	g_sh.red = malloc(sizeof(t_node));
	*g_sh.red = NULL;
	while (envp[++i])
		save_envp(envp[i], &lst);
	g_sh.node = &lst;
	init_shell();
	minishell_loop();
}
