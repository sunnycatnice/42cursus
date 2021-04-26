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
# define KEYESC 17
# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYMOUSE 06
# define KEYPRESSMASK 1L<<0
# define KEYRELEASEMASK 1L<<1
# define KEYRELEASEMOUSE 1L<<6
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
#define	CPP_MAP a->map
#define VP_MLX a->mlx.mlx
#define VP_WIN a->mlx.win
#define VP_IMG a->data.img
#define CP_ADDR a->data.addr
#define CP_CURR_IDE a->map_in.current_ide
#define CP_REAL_IDE a->map_in.real_ide
#define CP_TEX_FD a->map_in.tex_fd
#define CPP_INPUT a->map_in.input
#define I_BPP a->data.bits_per_pixel
#define I_LL a->data.line_length
#define I_INPUT_DEFINED a->in.defined
#define I_ENDIAN a->data.endian
#define VP_TXT_IMG a->txt
#define VP_ENDGAME_IMG a->endgame.img
#define I_W a->keycode.w
#define	I_A a->keycode.a
#define I_S a->keycode.s
#define I_D a->keycode.d
#define I_AR a->keycode.ar
#define I_AL a->keycode.al
#define I_ESC a->keycode.esc
#define I_SAVE_FLAG a->flags.save
#define UCP_SCREEN a->flags.screenshot
#define I_FINISH_FLAG a->flags.finish
#define I_NO a->dir.no
#define I_SO a->dir.so
#define I_EA a->dir.ea
#define I_WE a->dir.we
#define I_GNL_FD a->map_in.gnl_fd
#define I_FIRST_SPACE a->map_in.gnl_first_space
#define CP_GNL_LINE a->map_in.line
#define I_MAP_LINES a->map_in.map_lines
#define I_XSTART a->point.x_start
#define I_YSTART a->point.y_start
#define I_XPL a->point.x_pl
#define I_YPL a->point.y_pl
#define I_RES_WIDTH a->in.res_width
#define I_RES_HEIGHT a->in.res_height
#define I_COLOR_FLOOR a->in.color_floor
#define I_COLOR_CEILING a->in.color_ceiling
#define CP_TEXT_S a->in.txt_s
#define CP_TEXT_NO a->in.txt_no
#define CP_TEXT_SO a->in.txt_so
#define CP_TEXT_EA a->in.txt_ea
#define CP_TEXT_WE a->in.txt_we
#define CP_TEXT_FLOOR a->in.txt_floor
#define CP_TEXT_CEILING a->in.txt_ceiling
#define I_MAP_WIDTH a->in.map_width
#define I_MAP_HEIGHT a->in.map_height
#define I_PLAYER a->in.player
#define I_PLAYER_X a->player.posx
#define I_PLAYER_Y a->player.posy
#define I_AT_MAP_CLONE a->in.at_map_clone

#endif