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

static char	**list_to_matrix(t_all *all, t_list **list, int size)
{
	int 	i;
	t_list	*tmp;

	if (!(CPP_MAP = (char **)malloc((size + 1) * sizeof(char **))))
		return (NULL);
	tmp = *list;
	i = 0;
	while (tmp)
	{
		CPP_MAP[i] = CP_GNL_LINE;
		tmp = tmp->next;
		i++;
	}
	CPP_MAP[i] = NULL;
	ft_lstclear(list, &free);
	return (CPP_MAP);
}

void		map_to_list(t_all *all)
{
	t_list	*list;

	list = NULL;
	while (get_next_line(I_GNL_FD, &CP_GNL_LINE))
	{
		ft_lstadd_back(&list, ft_lstnew(CP_GNL_LINE));
		printf("LIST N. %-2d: %s\n", I_MAP_LINES, list->content);
		I_MAP_LINES++;
		list = list->next;
	}
	close (I_GNL_FD);
	ft_lstadd_back(&list, ft_lstnew(CP_GNL_LINE));
	printf("LIST N. %-2d: %s\n", I_MAP_LINES, list->content);
	I_MAP_LINES++;
	list_to_matrix(all, &list, I_MAP_LINES);
}

void		input_manager(t_all *all)
{
	map_to_list(all);
}