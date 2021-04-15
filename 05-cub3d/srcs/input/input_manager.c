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

static void	ft_take_data(t_a *a, int i)
{
	if (i < 5)
		ft_take_texture(a, i);
	else if (i == 5)
		ft_take_res(a);
	else if (i > 5)
		ft_take_color_or_texture(a, i);
}

static void	ft_store_data(t_a *a)
{
	static int	at_map = 0;
	int			i;

	i = 0;
	a->map_in.current_ide = ft_first_split(a->map_in.line);
	if (!a->map_in.current_ide)
		ft_print_error(a, 0);
	while (i < 8)
	{
		if (!ft_strcmp(a->map_in.current_ide, a->map_in.real_ide[i]))
		{
			ft_take_data(a, i);
			at_map++;
			free(a->map_in.current_ide);
			a->map_in.current_ide = 0;
			break ;
		}
		i++;
	}
	if (i == 8)
		ft_print_error(a, 6);
	a->in.at_map_clone++;
}

static void	ft_get_data(t_a *a)
{
	int	line;

	ft_print_start();
	printf("Processing: GNL to structure...\n");
	line = ft_get_next_line(a->map_in.gnl_fd, &a->map_in.line);
	while (line > 0)
	{
		if (a->in.at_map_clone < 8)
		{
			printf("Parsed line n. %-2d: %s\n", a->map_in.map_lines, a->map_in.line);
			if (!(!a->map_in.line[0] || ft_isspace_string(a->map_in.line)))
				ft_store_data(a);
			line = ft_get_next_line(a->map_in.gnl_fd, &a->map_in.line);
			a->map_in.map_lines++;
		}
		else
		{
			msg(0);
			break ;
		}
	}
}

void	ft_input_manager(t_a *a)
{
	t_list	*list;

	list = ft_lstnew("");
	ft_get_data(a);
	ft_map_to_list(a, list);
	control_map(a);
	adjust_map(a);
	close(a->map_in.gnl_fd);
}
