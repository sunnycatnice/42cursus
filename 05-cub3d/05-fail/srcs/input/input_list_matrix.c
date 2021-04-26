/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_list_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:04:08 by dmangola          #+#    #+#             */
/*   Updated: 2021/04/08 15:04:39 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_list_to_matrix(t_a *a, t_list *list)
{
	a->map_in.map_lines = 0;
	list = list->next;
	a->map = calloc((ft_lstsize(list) + 1), sizeof(char *));
	printf("Processing 3: From list to matrix...\n");
	while (!(list == NULL))
	{
		a->map[a->map_in.map_lines] = list->content;
		printf("Matrix line n. %-2d: %s\n", a->map_in.map_lines,
			a->map[a->map_in.map_lines]);
		check_width(a);
		list = list->next;
		a->map_in.map_lines++;
	}
	a->in.map_height = a->map_in.map_lines;
	a->map[a->map_in.map_lines] = "\0";
	msg(2);
}

void	ft_map_to_list(t_a *a, t_list *list)
{
	int		lines;
	t_list	*tmp;

	a->map_in.map_lines = 0;
	tmp = list;
	printf("Processing 2: GNL map to list...\n");
	lines = ft_get_next_line(a->map_in.gnl_fd, &a->map_in.line);
	while (lines > 0)
	{
		if (a->map_in.map_lines > 0)
			lines = ft_get_next_line(a->map_in.gnl_fd, &a->map_in.line);
		ft_lstadd_back(&tmp, ft_lstnew(a->map_in.line));
		a->map_in.map_lines++;
		tmp = tmp->next;
		printf("Exported to list n. %-2d: %s\n", a->map_in.map_lines,
			tmp->content);
	}
	msg(1);
	ft_list_to_matrix(a, list);
}
