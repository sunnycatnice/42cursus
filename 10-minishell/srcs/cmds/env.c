/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:33:17 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../../libft/incs/libft.h"

void	print_matrix(char **matrix)
{
	int		i;
	int		j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			ft_putchar_fd(matrix[i][j], 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
}

static int	ft_lstcount(t_node *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

static char	*ft_strcat3(char *s1, char *s2, char *s3)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2) + ft_strlen(s3) + 1));
	if (!(str))
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	i = -1;
	while (s3[++i])
		str[i + j + i] = s3[i];
	str[i + j + i] = '\0';
	return (str);
}

char	**from_list_to_mtx(t_node *env_list)
{
	char	**envp_mtx;
	int		i;
	t_node	*current;

	i = 0;
	current = env_list;
	envp_mtx = (char **)malloc(sizeof(char *) * (ft_lstcount(current) + 1));
	while (current != NULL)
	{
		envp_mtx[i] = ft_strcat3(current->name, "=", current->string);
		current = current->next;
		i++;
	}
	envp_mtx[i] = NULL;
	return (envp_mtx);
}

int	ft_env(int sent)
{
	t_node	*new;

	new = *g_sh.node;
	continue_env(new, sent);
	return (0);
}
