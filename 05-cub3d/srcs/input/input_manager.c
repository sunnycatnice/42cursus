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

static char	**list_to_matrix(t_all *all, t_list *list)
{
	int 	i;

	i = 0;
	CPP_MAP = calloc((ft_lstsize(list) + 1), sizeof(char *));
	while (!(list->next == NULL))
	{
		CPP_MAP[i] = list->content;
		printf("Matrix N. %-2d: %s\n\n", i, CPP_MAP[i]);
		list = list->next;
		i++;
	}
	return (CPP_MAP);
}

void		map_to_list(t_all *all, t_list *list)
{
	int lines;

	while ((lines = get_next_line(I_GNL_FD, &CP_GNL_LINE)) > 0)
	{
		ft_lstadd_back(&list, ft_lstnew(CP_GNL_LINE));
		printf("LIST N. %-2d: %s\n", I_MAP_LINES, list->content);
		I_MAP_LINES++;
		list = list->next;
	}
	if(lines == 0)
	{
		ft_lstadd_back(&list, ft_lstnew(CP_GNL_LINE));
		list = list->next;
	}
	ft_lstadd_back(&list, ft_lstnew(CP_GNL_LINE));
	printf("LIST N. %-2d: %s\n\n", I_MAP_LINES, list->content);
	I_MAP_LINES++;
	list_to_matrix(all, list);
}

void		input_manager(t_all *all)
{
	t_list	*list;

	list = ft_lstnew("");
	map_to_list(all, list);
	close(I_GNL_FD);
}