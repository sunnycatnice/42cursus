/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:11:20 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/17 15:11:21 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		all_map_input_free(t_all *all)
{
	if(I_GNL_FD > -1)
		close(I_GNL_FD);
	if(all->map_input.tex_fd > -1)
		close(all->map_input.tex_fd);
	if(CP_GNL_LINE)
		free(CP_GNL_LINE);
	if(all->map_input.current_ide)
		free(all->map_input.current_ide);
}


void		get_next_line_free(t_all *all)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(all->map_input.gnl_fd, &line)) >= 0)
	{
		free(line);
		if (!ret)
			break ;
	}
}