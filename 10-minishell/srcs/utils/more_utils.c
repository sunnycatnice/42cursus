/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vceccaro <vceccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:10:22 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/22 21:09:26 by vceccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	matrix_check(char **matrix)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (matrix[k])
		k++;
	while (i < k)
	{
		if (matrix[i][0] == '=')
		{
			if (matrix[i][1] != 0)
			{
				matrix[i] = get_err_name(matrix[i]);
				printf("bash: %s not found\n", matrix[i]);
			}
			else
				printf("basg: bad assignment\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	parse_exp_matrix(char **matrix)
{
	int	i;
	int	sent;
	int	j;

	i = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		sent = 0;
		while (matrix[i][j++])
		{
			if (matrix[i][j] == '=')
			{
				sent = 1;
				exp_has_content(matrix[i]);
			}
			j++;
		}
		if (sent == 0)
			if (!(exp_exists(matrix[i])))
				new_exp(matrix[i]);
		i++;
	}
}

void	continue_env(t_node *new, int sent)
{
	if (new->next != NULL)
	{
		while (new->next != NULL)
		{
			printf("%s %s\n", new->name, (char *)new->string);
			new = new->next;
		}
	}
	printf("%s %s\n", new->name, (char *)new->string);
	if (sent == 1)
		print_export(1);
}

void	continue_print_export(t_node *p, int sent)
{
	char	*id;
	char	*content;

	if (!(p))
		return ;
	while (p)
	{
		if (!(p->name))
			return ;
		id = p->name;
		content = (char *)p->string;
		if (sent == 0)
			printf("declare -x ");
		if (content)
			printf("%s=%s\n", id, content);
		else
			printf("%s=\n", id);
		p = p->next;
	}
}

void	continue_put_data_var(char *name, char *content)
{
	t_node	*var;

	var = *g_sh.var;
	while (var)
	{
		if (!(ft_strncmp(name, var->name, ft_strlen(name))))
		{
			if (var->string != NULL)
				free(var->string);
			var->string = ft_strdup(content);
			break ;
		}
		var = var->next;
	}
}
