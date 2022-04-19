/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:33:43 by bde-luca          #+#    #+#             */
/*   Updated: 2022/04/19 15:13:25 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export(int sent)
{
	t_node	*new;

	if (sent == 0)
	{
		new = *g_sh.node;
		if (!(ft_strncmp(new->name, "OLDPWD", 6)))
		{
			if (!(g_sh.firstoldpwd))
				printf("declare -x OLDPWD=%s\n", g_sh.oldpwd);
			new = new->next;
		}
		if (!(ft_strncmp(new->name, "PWD", 3)))
		{
			printf("declare -x PWD=%s\n", g_sh.pwd);
			new = new->next;
		}
		while (new->next != NULL)
		{
			printf("declare -x %s %s\n", new->name, (char *)new->string);
			new = new->next;
		}
	}
	if (*g_sh.exp)
		continue_print_export(*g_sh.exp, sent);
}

void	exp_has_content(char *longstring)
{
	int		i;
	t_node	*exp;
	char	*name;
	char	*string;

	exp = NULL;
	name = NULL;
	name = get_name(longstring, name);
	i = ft_strlen(name) + 1;
	string = ft_substr(longstring, i, ft_strlen(longstring) - i);
	if (!(check_existance(name)))
	{
		exp = malloc(sizeof(t_node *));
		exp->name = malloc(sizeof(char *));
		exp->name = ft_strdup(name);
		exp->string = ft_strdup(string);
		exp->next = NULL;
		ft_lstaddnode_back(g_sh.exp, exp);
	}
	else
		add_exp_info(name, string);
	free(name);
	free(string);
}

void	new_exp(char *name)
{
	t_node	*exp;
	int		i;
	char	*tmp;

	i = 0;
	exp = NULL;
	while (name[i] != '=')
		i++;
	tmp = ft_substr(name, i + 1, ft_strlen(name) - i - 1);
	name = ft_substr(name, 0, i);
	if (!(get_node(name)))
	{
		exp = malloc(sizeof(t_node));
		exp->name = ft_strdup(name);
		exp->string = ft_strdup(tmp);
		exp->next = NULL;
		ft_lstaddnode_back(g_sh.exp, exp);
	}
	free(tmp);
}

int	ft_export(char *name)
{
	int		i;
	char	**matrix;

	i = 1;
	while (name[i])
		i++;
	if (i == 6)
	{
		print_export(0);
		return (0);
	}
	name = ft_substr(name, 7, i);
	if (name[0] == ' ' || name[0] == '$')
		name = takeout_spaces(name);
	matrix = ft_bnessi_split(name, ' ');
	free(name);
	if (!(matrix_check(matrix)))
	{
		free_matrix(matrix);
		return (0);
	}
	parse_exp_matrix(matrix);
	free_matrix(matrix);
	return (0);
}

char	*extract_string(char *str, int stop)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = malloc(sizeof(stop));
	while (i <= stop)
	{
		ret[i] = str[j];
		i++;
		j++;
	}
	str = ft_strdup(ret);
	free(ret);
	return (str);
}
