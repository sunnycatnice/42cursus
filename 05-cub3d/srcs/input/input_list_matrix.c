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

void	ft_list_to_matrix(t_all *all, t_list *list)
{
	I_MAP_LINES = 0;
	list = list->next;
	CPP_MAP = calloc((ft_lstsize(list) + 1), sizeof(char *));
	printf("Processing 3: From list to matrix...\n");
	while (!(list == NULL))
	{
		CPP_MAP[I_MAP_LINES] = list->content;
		printf("Matrix line n. %-2d: %s\n", I_MAP_LINES, CPP_MAP[I_MAP_LINES]);
		list = list->next;
		I_MAP_LINES++;
	}
	CPP_MAP[I_MAP_LINES] = "\0";
	msg(2);
}

void	ft_map_to_list(t_all *all, t_list *list)
{
	int		lines;
	t_list	*tmp;

	tmp = list;
	printf("Processing 2: GNL map to list...\n");
	lines = ft_get_next_line(I_GNL_FD, &CP_GNL_LINE);
	while (lines > 0)
	{
		if (I_MAP_LINES > 0)
			lines = ft_get_next_line(I_GNL_FD, &CP_GNL_LINE);
		ft_lstadd_back(&tmp, ft_lstnew(CP_GNL_LINE));
		I_MAP_LINES++;
		tmp = tmp->next;
		printf("Exported to list n. %-2d: %s\n", I_MAP_LINES, tmp->content);
	}
	msg(1);
	ft_list_to_matrix(all, list);
}
