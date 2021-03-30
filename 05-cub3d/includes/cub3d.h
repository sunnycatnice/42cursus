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
# include "../libs/mlx/minilibx_opengl_20191021/mlx.h"
/*
** Including all header files
*/
# include "define.h"
# include "struct.h"

int				main(int ac, char **av);
void			init_input(t_all *all);
void			init_map_input(t_all *all);
/*
** Input part
*/
void			red_color();
void			green_color();
void			reset_color();
void			print_start();
void			print_error(t_all *all, int n);
void			check_err(int n);
void			all_map_input_free(t_all *all);
void			get_next_line_free(t_all *all);
void			check_arg(t_all *all, int ac, char **av);
void			print_error(t_all *all, int n);
void			input_manager(t_all *all);
/*
** Game part
*/
void			game_manager(t_all *all);
void			init_game(t_all *all);
void			init_window(t_all *all);
void			init_dir(t_all *all);
void			init_keys(t_all *all);
int				key_hit(int keycode, t_all *all);
int				key_release(int keycode, t_all *all);
int				key_register(t_all *all);
void			draw_map(t_all *all);
void			draw_first_map(t_all *all);
void			get_player(t_all *all, int i, int j);
void			draw_player(t_all *all, int color);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			draw_pixel_size(t_all *all, int color);

#endif
