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

char	**ft_make_map(t_all **all, int size)
{
	int 	i;
	char	**map;
	t_list	*tmp;

	if(!(map = (char **)malloc((size + 1) * sizeof(char **))))
		return (NULL);
	tmp = all->list;
	i = 0;
	while (tmp)
	{
		map[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	ft_lstclear(&all->list, &free);
	return (map);
}

char	**ft_read_map(char *av1)
{
	int		size;
	t_all	*all;

	all = NULL;
	all->map_input.line = NULL;
	size = 0;
	all->map_input.gnl_fd = open(av1, O_RDONLY);
	while (get_next_line(all->map_input.gnl_fd, &all->map_input.line) > 0)
	{
		ft_lstadd_back(&all->list, ft_lstnew(all->map_input.line));
		printf("LIST N: %s\n", all->list.content);
		size++;
		all = all->list.next;
		all->map_input.line = NULL;
	}
	close (all->map_input.gnl_fd);
	ft_lstadd_back(&all->list, ft_lstnew(all->map_input.line));
	printf("LIST N: %s\n", all->list.content);
	all = all->list.content;	
	size++;
	return (ft_make_map(&all, size));
}