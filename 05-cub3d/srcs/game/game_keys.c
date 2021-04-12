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

static void	ft_forward(t_all *all)
{
	I_YPL -= 10;
}

static void	ft_backward(t_all *all)
{
	I_YPL += 10;
}

static void	ft_left(t_all *all)
{
	I_XPL -= 10;
}

static void	ft_right(t_all *all)
{
	I_XPL += 10;
}

int	ft_key_register(t_all *all)
{
	printf("if tasti\n");
	if (all->keyboard.keyboard[13])
		ft_forward(all);
	if (all->keyboard.keyboard[1])
		ft_backward(all);
	if (all->keyboard.keyboard[0])
		ft_left(all);
	if (all->keyboard.keyboard[2])
		ft_right(all);
	if (all->keyboard.keyboard[53])
	{
		printf("Tasto esc");
		mlx_destroy_image(VP_MLX, VP_IMG);
		mlx_destroy_window(VP_MLX, VP_WIN);
		exit (0);
	}
	printf("Esco if tasti\n");
	//mlx_destroy_image(VP_MLX, VP_IMG);
	printf("Destroy img\n");
	//VP_IMG = mlx_new_image(VP_MLX, 1920, 1080);
	printf("new image\n");
	//CP_ADDR = mlx_get_data_addr(VP_IMG, &I_BPP, &I_LL, &I_ENDIAN);
	printf("mlx data addr\n");
	//ft_draw_map(all);
	mlx_put_image_to_window(VP_MLX,VP_WIN, VP_IMG, 0, 0);
	return (0);
}
