/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:19:29 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/19 12:19:31 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
/*
** Drawing all others frames
*/
static void	draw_line(t_all *all, int i)
{
	short	j;

	j = 0;
	while (CPP_MAP[i][j])
	{
		if (CPP_MAP[i][j] == '1')
			draw_pixel_size(all, CYAN);
		else if (CPP_MAP[i][j] == '2')
			draw_pixel_size(all, BLUE);
		else if (CPP_MAP[i][j] == 'N' || CPP_MAP[i][j] == 'S'
			|| CPP_MAP[i][j] == 'E' || CPP_MAP[i][j] == 'W')
		{
			get_player(all, i, j);
			draw_player(all, RED);
			draw_pixel_size(all, RED);
		}
		else
			draw_pixel_size(all, BLACK);
		I_XSTART = I_XSTART + PIXEL_SIZE;
		j++;
	}
}

void	draw_map(t_all *all)
{
	int	i;

	I_YSTART = 200;
	i = 0;
	printf("Graphic part 2: drawing movement...\n");
	while (CPP_MAP[i])
	{
		I_XSTART = 200;
		printf("Drawing line n. %-2d: %s\n", i, CPP_MAP[i]);
		draw_line(all, i);
		I_YSTART = I_YSTART + PIXEL_SIZE;
		i++;
	}
}
/*
** Drawing the first frame
*/
static void	draw_first_line(t_all *all, int i)
{
	short	j;

	j = 0;
	while (CPP_MAP[i][j])
	{
		if (CPP_MAP[i][j] == '1')
			draw_pixel_size(all, CYAN);
		else if (CPP_MAP[i][j] == '2')
			draw_pixel_size(all, BLUE);
		else if (CPP_MAP[i][j] == 'N' || CPP_MAP[i][j] == 'S'
			|| CPP_MAP[i][j] == 'E' || CPP_MAP[i][j] == 'W')
		{
			get_player(all, i, j);
			draw_player(all, RED);
			draw_pixel_size(all, RED);
		}
		else
			draw_pixel_size(all, BLACK);
		I_XSTART = I_XSTART + PIXEL_SIZE;
		j++;
	}
}

void	draw_first_map(t_all *all)
{
	int	i;

	I_YSTART = 200;
	i = 0;
	printf("Graphic part 1: drawing map...\n");
	while (CPP_MAP[i])
	{
		I_XSTART = 200;
		printf("Drawing line n. %-2d: %s\n", i, CPP_MAP[i]);
		draw_first_line(all, i);
		I_YSTART = I_YSTART + PIXEL_SIZE;
		i++;
	}
}
