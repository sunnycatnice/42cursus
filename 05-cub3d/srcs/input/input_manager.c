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

char	**ft_make_map(t_list **list, int size)
{
	int 	i;
	char	**map;
	t_list	*tmp;

	if(!(map = (char **)malloc((size + 1) * sizeof(char **))))
		return (NULL);
	tmp = *list;
	i = 0;
	while (tmp)
	{
		map[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	ft_lstclear(list, &free);
	return (map);
}

char	**ft_read_map(t_all *all, char *av1)
{
	int		size;
	t_list	*list;

	list = NULL;
	size = 0;
	all->map_input.gnl_fd = open(av1, O_RDONLY);
	while (get_next_line(all->map_input.gnl_fd, &all->map_input.line))
	{
		ft_lstadd_back(&list, ft_lstnew(all->map_input.line));
		printf("LIST N: %s\n", list->content);
		size++;
		list = list->next;
		all->map_input.line = NULL;
	}
	close (all->map_input.gnl_fd);
	ft_lstadd_back(&list, ft_lstnew(all->map_input.line));
	printf("LIST N: %s\n", list->content);
	size++;
	return (ft_make_map(&list, size));
}