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

void	ft_game_manager(t_a *a)
{
	a->mlx.win = mlx_init();
	a->tex.no = (t_data *)malloc(sizeof(t_data));
	a->tex.so = (t_data *)malloc(sizeof(t_data));
	a->tex.we = (t_data *)malloc(sizeof(t_data));
	a->tex.ea = (t_data *)malloc(sizeof(t_data));
	a->tex.sp = (t_data *)malloc(sizeof(t_data));
	if (a->in.res_width > 2560)
		a->in.res_width = 2560;
	if (a->in.res_height > 1440)
		a->in.res_height = 1440;
	a->mlx.win = mlx_new_window(a->mlx.win, a->in.res_width, a->in.map_height,
			"Cub3D");
	engine_init(all);
	tex_init(all);
	spt_init(all);
	mlx_hook(cub.win, 02, 1L << 02, key_press, &cub);
	mlx_hook(cub.win, 03, 1L << 03, key_release, &cub);
	mlx_hook(cub.win, 17, 1L << 02, win_close, &cub);
	mlx_loop_hook(cub.mlx, render_frame, &cub);
	mlx_loop(cub.mlx);
}
