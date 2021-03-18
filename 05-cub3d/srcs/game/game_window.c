/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:28:20 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/18 15:28:23 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_get_player(char **map, t_all *all)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[x][y])
		{
			if(map[y][x] == 'N' || map[y][x] == 'S' || map [y][x] == 'E'
			|| map[y][x] == 'W')
			{
				all->player.pos_x = x * SCALE;
				all->player.pos_y = y * SCALE;
				if (map[y][x] == "N")
					all->player.dir = PI_3_2;
			}
		}
		
	}
}

void	ft_get_window(t_all *all)
{
	all->init = mlx_init();
	all->win = mlx_new_window(all->init, 1920, 1080, "Cub 3D");
	ft_get_player(all->input.map, &all);
	mlx_loop(all->init);
}