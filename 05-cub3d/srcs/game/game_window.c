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

void	game_manager(t_all *all)
{
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, 1920, 1080, "Cub 3D");
	all->win = all->win;
	ft_get_player(all->map, all);
	draw_map(all);
	mlx_loop(all->mlx);
}