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

static  void	ft_put_pixel(t_data *win, int x, int y, int color)
{
	char	*dst;

	printf("put_pixel\n");
	dst = win->addr + (x * (win->bits_per_pixel / 8) + y * win->line_length);
	*(int *)dst = color;
}

void	ft_scale_img(t_data *img, t_point point, int color)
{
	t_point end;

	end.x = (point.x + 1) * SCALE;
	end.y = (point.y + 1) * SCALE;
	point.y *= SCALE;
	point.x *= SCALE;
	printf("scele img\n");
	while (point.y < end.y)
	{
		printf("CICLO ESTERNO 1\n");
		while (point.x < end.x)
		{
			printf("%d, %d\n", point.x, end.x);
			ft_put_pixel(img, point.x, point.y, color);
			point.x++;
		}
		point.x -= SCALE;
		point.y++;
	}
}

int		draw_map(t_all *all)
{
	t_data	*data;
	t_point	point;

	data = &all->data;
	data->img = mlx_new_image(all->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
								&data->endian);
	ft_bzero(&point, sizeof(t_point));
	printf("PRIMA\n");
	while (all->map[point.x])
	{
		printf("CICLO ESTERNO\n");
		point.y = 0;
		while (all->map[point.x][point.y])
		{
			if (all->map[point.y][point.x] == '1')
			{
				printf("CICLO INTERNO\n");
				ft_scale_img(data->img, point, 0x00FFFF00);
			}
			point.y++;
		}
		point.x++;
	}
	printf("SECONDA\n");
    mlx_put_image_to_window(all->mlx, all->win, data->img, 15, 15);
	return (0);
}