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

void	ft_all_map_input_free(t_a *a)
{
	if (I_GNL_FD > -1)
		close(I_GNL_FD);
	if (a->map_in.tex_fd > -1)
		close(a->map_in.tex_fd);
	if (CP_GNL_LINE)
		free(CP_GNL_LINE);
	if (a->map_in.current_ide)
		free(a->map_in.current_ide);
}

void	ft_get_next_line_free(t_a *a)
{
	char	*line;
	int		ret;

	ret = ft_get_next_line(a->map_in.gnl_fd, &line);
	while (ret >= 0)
	{
		free(line);
		if (!ret)
			break ;
	}
}
