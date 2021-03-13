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

char	**ft_make_map(t_list **head, int size)
{
	int 	i;
	char	**map;
	t_list	*tmp;

	if(!(map = (char **)malloc((size + 1) * sizeof(char **))))
		return (NULL);
	tmp = *head;
	i = 0;
	while (tmp)
	{
		map[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	ft_lstclear(head, &free);
	return (map);
}

char	**ft_read_map(char *av1)
{
	int		fd;
	int		size;
	char	*line;
	t_list	*head;

	line = NULL;
	head = NULL;
	size = 0;
	fd = open(av1, O_RDONLY);
	while (get_next_line(fd, &line) >= 0)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		size++;
		line = NULL;
	}
	close (fd);
	ft_lstadd_back(&head, ft_lstnew(line));
	size++;
	return (ft_make_map(&head, size));
}