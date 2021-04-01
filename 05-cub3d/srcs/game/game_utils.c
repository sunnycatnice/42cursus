/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:23:09 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/19 17:23:11 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_draw_pixel_size(t_all *all, int color)
{
	int	l;
	int	h;

	h = I_YSTART;
	l = I_XSTART;
	while (h < (I_YSTART + PIXEL_SIZE))
	{
		l = I_XSTART;
		while (l < (I_XSTART + PIXEL_SIZE))
		{
			my_mlx_pixel_put(&all->data, l, h, color);
			l++;
		}
		h++;
	}
}
