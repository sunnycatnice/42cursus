/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:11:23 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/27 15:11:24 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_window(t_all *all)
{
	VP_MLX = mlx_init();
	VP_WIN = mlx_new_window(VP_MLX, 1920, 1080, "Cub 3D");
	VP_IMG = mlx_new_image(VP_MLX, 1920, 1080);
	CP_ADDR = mlx_get_data_addr(VP_IMG, &I_BPP, &I_LL, &I_ENDIAN);
}

void	init_dir(t_all *all)
{
	I_NO = 0;
	I_SO = 0;
	I_EA = 0;
	I_WE = 0;
}

void	init_keys(t_all *all)
{
	I_W = 0;
	I_A = 0;
	I_S = 0;
	I_D = 0;
	I_ESC = 0;
}

void	init_game(t_all *all)
{
	init_window(all);
	init_keys(all);
}
