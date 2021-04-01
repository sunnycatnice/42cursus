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
	ft_draw_first_map(all);
	//mlx_put_image_to_window(VP_MLX, VP_WIN, VP_IMG, 0, 0);
	mlx_hook(VP_WIN, KEYPRESS, KEYPRESSMASK, ft_key_hit, &all);
	mlx_hook(VP_WIN, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &all);
	//mlx_loop_hook(VP_MLX, key_register, &all);
	mlx_loop(VP_MLX);
}
