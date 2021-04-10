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
** UTILS
*/
#define	SCALE 128
#define PIXEL_SIZE 32
#define PLAYER_SIZE 4
/*
** KEYS
*/
# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK 1L
# define KEYRELEASEMASK 2L
/*
** COLORS
*/
#define CYAN 0x0000FFFF
#define BLUE 0x00000FFF
#define RED 0x00FF0000
#define BLACK 0x00000000
/*
** PI
*/
#define PI M_PI
#define PI_2 M_PI / 2
#define PI_3_4 M_PI * 3 / 4
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
#define	CPP_MAP all->map
#define VP_MLX all->mlx.mlx
#define VP_WIN all->mlx.win
#define VP_IMG all->data.img
#define CP_ADDR all->data.addr
#define CP_CURR_IDE all->map_input.current_ide
#define CP_REAL_IDE all->map_input.real_ide
#define CP_TEX_FD all->map_input.tex_fd
#define CPP_INPUT all->map_input.input
#define I_BPP all->data.bits_per_pixel
#define I_LL all->data.line_length
#define I_INPUT_DEFINED all->input.defined
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
#define I_FIRST_SPACE all->map_input.gnl_first_space
#define CP_GNL_LINE all->map_input.line
#define I_MAP_LINES all->map_input.map_lines
#define F_PPX all->player.pos_x
#define F_PPY all->player.pos_y
#define I_XSTART all->point.x_start
#define I_YSTART all->point.y_start
#define I_XPL all->point.x_pl
#define I_YPL all->point.y_pl
#define I_KEYBOARD all->keyboard.keyboard
#define I_RES_WIDTH all->input.res_width
#define I_RES_HEIGHT all->input.res_height
#define I_COLOR_FLOOR all->input.color_floor
#define I_COLOR_CEILING all->input.color_ceiling
#define CP_TEXT_S all->input.texture_s
#define CP_TEXT_NO all->input.texture_no
#define CP_TEXT_SO all->input.texture_so
#define CP_TEXT_EA all->input.texture_ea
#define CP_TEXT_WE all->input.texture_we
#define CP_TEXT_FLOOR all->input.texture_floor
#define CP_TEXT_CEILING all->input.texture_ceiling
#define I_MAP_WIDTH all->input.map_width
#define I_MAP_HEIGHT all->input.map_height
#define I_PLAYER all->input.player
#define I_PLAYER_X all->input.player_x
#define I_PLAYER_Y all->input.player_y
#define I_SAVE_FLAG all->input.save_flag


#endif