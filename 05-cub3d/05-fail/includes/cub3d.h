/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:28:05 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/08 15:28:07 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
/*
** Including libft && minilibx
*/
# include "../libs/libft/libft.h"
# include "../libs/mlx/minilibx_mms_20200219/mlx.h"
/*
** Including all header files
*/
# include "define.h"
# include "struct.h"

int				main(int ac, char **av);
void			ft_init_input(t_a *a);
void			ft_init_map_input(t_a *a);
/*
** ---------------------------------------------------------------------------
** 									INPUT PART
** ---------------------------------------------------------------------------
*/
void			ft_input_manager(t_a *a);
/*
** Colors and different printed messages
*/
void			ft_print_start(void);
void			ft_red_color(void);
void			ft_green_color(void);
void			ft_reset_color(void);
void			ft_check_err(int n);
void			ft_print_error(t_a *a, int n);
void			msg(int n);
/*
** Saving data into structure
*/
void			ft_take_input(t_a *a);
void			ft_take_texture(t_a *a, int i);
void			ft_take_res(t_a *a);
void			ft_take_color_or_texture(t_a *a, int i);
void			ft_map_to_list(t_a *a, t_list *list);
/*
** Saving MAP into list --> matrix then check
*/
void			ft_all_map_input_free(t_a *a);
void			ft_get_next_line_free(t_a *a);
void			ft_check_arg(t_a *a, int ac, char **av);
void			ft_list_to_matrix(t_a *a, t_list *list);
void			check_width(t_a *a);
void			control_map(t_a *a);
void			control_constraits(t_a *a, int i, int j);
void			adjust_map(t_a *a);
/*
** ---------------------------------------------------------------------------
** 									GAME PART
** ---------------------------------------------------------------------------
*/
void			ft_game_manager(t_a *a);
/*
** Init game part
*/
void			ft_init_game(t_a *a);
void			ft_init_window(t_a *a);
void			ft_init_dir(t_a *a);
void			ft_init_keys(t_a *a);
/*
** Key hook fts
*/
int				close_program_x(t_a *a);
int				init_move_press(int keycode, t_a *a);
int				init_move_release(int keycode, t_a *a);
int				move_mouse(int pos, t_a *a);
/*
** Raycasting part
*/
int				render_frame(t_a *a);
int				ft_check_flags(t_a *a);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
