/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:11:30 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/17 12:11:31 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_map_input(t_a *a)
{
	a->map_in.gnl_fd = -1;
	a->map_in.tex_fd = -1;
	a->map_in.map_lines = 0;
	a->in.map_width = 0;
	a->in.map_height = 0;
	a->map_in.line = 0;
	a->map_in.input = 0;
	a->map_in.real_ide[0] = "S";
	a->map_in.real_ide[1] = "NO";
	a->map_in.real_ide[2] = "SO";
	a->map_in.real_ide[3] = "EA";
	a->map_in.real_ide[4] = "WE";
	a->map_in.real_ide[5] = "R";
	a->map_in.real_ide[6] = "C";
	a->map_in.real_ide[7] = "F";
}

void	ft_init_input(t_a *a)
{
	short	i;

	i = 0;
	while (i < 8)
		a->in.defined[i++] = 0;
	a->in.at_map_clone = 0;
	a->mlx.mlx = NULL;
	a->mlx.win = NULL;
}
