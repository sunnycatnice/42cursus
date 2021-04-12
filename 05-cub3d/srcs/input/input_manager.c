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

static void	ft_take_data(t_all *all, int i)
{
	if (i < 5)
		ft_take_texture(all, i);
	else if (i == 5)
		ft_take_res(all);
	else if (i > 5)
		ft_take_color_or_texture(all, i);
}

static void	ft_store_data(t_all *all)
{
	static int	at_map = 0;
	int			i;

	i = 0;
	CP_CURR_IDE = ft_first_split(CP_GNL_LINE);
	if (!CP_CURR_IDE)
		ft_print_error(all, 0);
	while (i < 8)
	{
		if (!ft_strcmp(CP_CURR_IDE, CP_REAL_IDE[i]))
		{
			ft_take_data(all, i);
			at_map++;
			free(CP_CURR_IDE);
			CP_CURR_IDE = 0;
			break ;
		}
		i++;
	}
	if (i == 8)
		ft_print_error(all, 6);
	I_AT_MAP_CLONE++;
}

static void	ft_get_data(t_all *all)
{
	int	lines;

	ft_print_start();
	printf("Processing: GNL to structure...\n");
	lines = ft_get_next_line(I_GNL_FD, &CP_GNL_LINE);
	while (lines > 0)
	{
		if (I_AT_MAP_CLONE < 8)
		{
			printf("Parsed line n. %-2d: %s\n", I_MAP_LINES, CP_GNL_LINE);
			if (!(!CP_GNL_LINE[0] || ft_isspace_string(CP_GNL_LINE)))
				ft_store_data(all);
			lines = ft_get_next_line(I_GNL_FD, &CP_GNL_LINE);
			I_MAP_LINES++;
		}
		else
		{
			msg(0);
			break ;
		}
	}
	I_MAP_LINES = 0;
}

void	ft_input(t_all *all)
{
	t_list	*list;

	list = ft_lstnew("");
	ft_get_data(all);
	ft_map_to_list(all, list);
	close(I_GNL_FD);
}
