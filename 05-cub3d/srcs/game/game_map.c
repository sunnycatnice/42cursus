/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:19:29 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/19 12:19:31 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		draw_map(t_all *all)
{
	t_data	img;
	int		x;
	int		y;

	img.img = mlx_new_image(all->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	x = -1;
	while (all->input.map[x] && x++)
	{
		y = -1;
		while (all->input.map[x][y] && y++)
		{
			if (all->input.map[x][y] == '1')
				my_mlx_pixel_put(&img, x, y, 0x00FFFF00);
		}
	}
    mlx_put_image_to_window(all->mlx, all->win, img.img, 15, 15);
	return (0);
}