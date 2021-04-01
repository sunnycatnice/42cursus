/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:31:21 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/19 14:31:23 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_player(t_all *all, int i, int j)
{
	F_PPX = I_XSTART;
	F_PPY = I_YSTART;
	if (CPP_MAP[i][j] == 'N')
		all->player.dir = PI_2;
	else if (CPP_MAP[i][j] == 'S')
		all->player.dir = PI_3_4;
	else if (CPP_MAP[i][j] == 'E')
		all->player.dir = 2 * PI;
	else if (CPP_MAP[i][j] == 'W')
		all->player.dir = PI;
	return ;
}

void	draw_player(t_all *all, int color)
{
	int	l;
	int	h;

	h = I_YSTART;
	l = I_XSTART;
	while (h < (I_YSTART + PLAYER_SIZE))
	{
		l = I_XSTART;
		while (l < (I_XSTART + PLAYER_SIZE))
		{
			my_mlx_pixel_put(&all->data, l, h, color);
			l++;
		}
		h++;
	}
}
