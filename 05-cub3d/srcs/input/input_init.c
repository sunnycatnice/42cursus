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

void	ft_init_map_input(t_all *all)
{
	I_GNL_FD = -1;
	CP_TEX_FD = -1;
	I_MAP_LINES = 0;
	I_MAP_WIDTH = 0;
	I_MAP_HEIGHT = 0;
	CP_GNL_LINE = 0;
	CP_CURR_IDE = 0;
	CPP_INPUT = 0;
	CP_REAL_IDE[0] = "S";
	CP_REAL_IDE[1] = "NO";
	CP_REAL_IDE[2] = "SO";
	CP_REAL_IDE[3] = "EA";
	CP_REAL_IDE[4] = "WE";
	CP_REAL_IDE[5] = "R";
	CP_REAL_IDE[6] = "C";
	CP_REAL_IDE[7] = "F";
}

void	ft_init_input(t_all *all)
{
	short	i;

	i = 0;
	while (i < 8)
		I_INPUT_DEFINED[i++] = 0;
	I_AT_MAP_CLONE = 0;
	VP_MLX = NULL;
	VP_WIN = NULL;
}
