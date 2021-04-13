/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:28:20 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/18 15:28:23 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_game_manager(t_all *all)
{
	ft_init_game(all);
	mlx_hook(VP_WIN, KEYESC, KEYPRESSMASK, close_program_x, &all);
	mlx_hook(VP_WIN, KEYPRESS, KEYPRESSMASK, init_move_press, &all);
	mlx_hook(VP_WIN, KEYRELEASE, KEYRELEASEMASK, init_move_release, &all);
	mlx_hook(VP_WIN, KEYMOUSE, KEYRELEASEMASK, move_mouse, &all);
	mlx_loop_hook(VP_MLX, render_frame, &all);
	// mlx_loop(VP_MLX);
}
