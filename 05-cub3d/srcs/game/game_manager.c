/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                      :+:      :+:    :+:   */
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
	init_game(all);
	ft_get_player(CPP_MAP, all);
	draw_map(all);
	mlx_loop(VP_MLX);
}