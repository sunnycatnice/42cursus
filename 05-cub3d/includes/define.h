/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:45:10 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/13 11:49:04 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
 * LEGEND
 * FIRST:
 *
 * V = void
 * C = char
 * I = int
 * F = float
 * D = double
 *
 * SECOND:
 * P = *
 * PP = **
 * ?V = ?[]
 * T = typedef
 *
 * Es: IPV_ES = int *ES[]
 */

#define	SCALE 128
#define PIXEL_SIZE 32
#define PI M_PI
#define PI_2 M_PI / 2
#define PI_3_2 M_PI * 3 / 2

#define	CPP_MAP all->map
#define VP_MLX all->mlx.mlx
#define VP_WIN all->mlx.win
#define VP_IMG all->data.img
#define CP_ADDR all->data.addr
#define I_BPP all->data.bits_per_pixel
#define I_LL all->data.line_length
#define I_ENDIAN all->data.endian
#define I_W all->keys.w
#define	I_A all->keys.a
#define I_S all->keys.s
#define I_D all->keys.d
#define I_ESC all->keys.esc
#define I_NO all->dir.no
#define I_SO all->dir.so
#define I_EA all->dir.ea
#define I_WE all->dir.we
#define I_GNL_FD all->map_input.gnl_fd
#define CP_GNL_LINE all->map_input.line
#define I_MAP_LINES all->map_input.map_lines

#endif