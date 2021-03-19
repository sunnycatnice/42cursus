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

void	ft_get_player(char **map, t_all *all)
{
	int x;
	int y;

	x = -1;
	while (map[x] && x++)
	{
		y = -1;
		while (map[x][y] && y++)
		{
			if (map[x][y] == 'N' || map[x][y] == 'S' || map[x][y] == 'E'
			|| map[x][y] == 'W')
			{
				all->player.pos_x = x * SCALE;
				all->player.pos_y = y * SCALE;
				if (map[y][x] == 'N')
					all->player.dir = PI_3_2;
				else if (map[y][x] == 'E')
					all->player.dir = 2 * PI;
				else if (map[y][x] == 'S')
					all->player.dir = PI_2;
				else if (map[y][x] == 'W')
					all->player.dir = PI;
				return ;
			}
		}
	}
}