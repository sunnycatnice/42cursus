/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:52:54 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/05 16:52:55 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;

    mlx = mlx_init();
    img.img = mlx_new_image(mlx, 1920, 1080);
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_length,
                                &img.endian);
    mlx_loop(mlx);
}