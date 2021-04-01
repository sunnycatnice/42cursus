/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:20:28 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/11 13:20:30 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	list_to_matrix(t_all *all, t_list *list)
{
	I_MAP_LINES = 0;
	list = list->next;
	CPP_MAP = calloc((ft_lstsize(list) + 1), sizeof(char *));
	printf("Processing: From list to matrix...\n");
	while (!(list == NULL))
	{
		CPP_MAP[I_MAP_LINES] = list->content;
		printf("Matrix line n. %-2d: %s\n", I_MAP_LINES, CPP_MAP[I_MAP_LINES]);
		list = list->next;
		I_MAP_LINES++;
	}
	green_color();
	printf("\n\u2714 Successful import!\n\n");
	reset_color();
}

static void	map_to_list(t_all *all, t_list *list)
{
	int		lines;
	t_list	*tmp;

	tmp = list;
	print_start();
	printf("Processing: GNL from .cub file to list...\n");
	lines = ft_get_next_line(I_GNL_FD, &CP_GNL_LINE);
	while (lines > 0)
	{
		if (I_MAP_LINES > 0)
			lines = ft_get_next_line(I_GNL_FD, &CP_GNL_LINE);
		ft_lstadd_back(&tmp, ft_lstnew(CP_GNL_LINE));
		I_MAP_LINES++;
		tmp = tmp->next;
		printf("Exporting to list n. %-2d: %s\n", I_MAP_LINES, tmp->content);
	}
	green_color();
	printf("\u2714 Export done!\n\n");
	reset_color();
	list_to_matrix(all, list);
}

void	input_manager(t_all *all)
{
	t_list	*list;

	list = ft_lstnew("");
	map_to_list(all, list);
	close(I_GNL_FD);
}
