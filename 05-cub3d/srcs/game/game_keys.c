/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_basic_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:48:23 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/30 12:48:25 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int close_program_x(t_all *all)
{
	msg(3);
	mlx_destroy_image(VP_MLX, VP_IMG);
	mlx_destroy_window(VP_MLX, VP_WIN);
	exit(0);
}

int	init_move_press(int keycode, t_all *all)
{
	if (keycode == 13)
		I_W = 1;
	if (keycode == 1)
		I_S = 1;
	if (keycode == 0)
		I_A = 1;
	if (keycode == 2)
		I_D = 1;
	if (keycode == 124)
		I_AR = 1;
	if (keycode == 123)	
		I_AL = 1;
	if (keycode == 53)
		I_ESC = 1;
	return (0);
}

int	init_move_release(int keycode, t_all *all)
{
	if (keycode == 13)
		I_W = 0;
	if (keycode == 1)
		I_S = 0;
	if (keycode == 0)
		I_A = 0;
	if (keycode == 2)
		I_D = 0;
	if (keycode == 124)
		I_AR = 0;
	if (keycode == 123)	
		I_AL = 0;
	if (keycode == 53)
		I_ESC = 0;
	return (0);
}

int	move_mouse(int pos, t_all *all)
{
	static	int tmp;

	if (tmp == pos || (pos >= (tmp - 5) && pos <= (tmp + 5)))
	{
		I_AR = 0;
		I_AL = 0;
		return 0;
	}

	if (tmp > pos)
	{
		I_AR = 0;
		I_AL = 1;

	}
	else
	{
		I_AR = 1;
		I_AL = 0;
	}
	tmp = pos;
	return (1);
}