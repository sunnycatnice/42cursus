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

static void	draw_line(t_all *all, int x, int y, int i)
{
	int j;

	j = 0;
	while (CPP_MAP[i][j])
	{
		if (CPP_MAP[i][j] == '1')
			draw_pixel_size(all, x, y, CYAN);
		else if (CPP_MAP[i][j] == '2')
			draw_pixel_size(all, x, y, BLUE);
		else if (CPP_MAP[i][j] == 'N' || CPP_MAP[i][j] == 'S' ||
			CPP_MAP[i][j] == 'E' || CPP_MAP[i][j] == 'W')
		{
			ft_get_player(all, x, y, i, j);
			draw_pixel_size(all, x, y, RED);
		}
		else
			draw_pixel_size(all, x, y, BLACK);
		x = x + PIXEL_SIZE;
		j++;
	}
}

void		draw_map(t_all *all)
{
	int x;
	int y;
	int i;

	x = 50;
	y = 50;
	i = 0;
	printf("Grafic part: reading map...\n");
	while (CPP_MAP[i])
	{
		printf("Matrix line n. %-2d: %s\n", i, CPP_MAP[i]);
		draw_line(all, x, y, i);
		y = y + PIXEL_SIZE;
		i++;
	}
}