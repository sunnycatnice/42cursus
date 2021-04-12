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
void			ft_init_input(t_all *all);
void			ft_init_map_input(t_all *all);
/*
** Input part
*/
void			ft_red_color();
void			ft_green_color();
void			ft_reset_color();
void			ft_print_start();
void			msg(int n);
void			ft_print_error(t_all *all, int n);
void			ft_check_err(int n);
void			ft_all_map_input_free(t_all *all);
void			ft_get_next_line_free(t_all *all);
void			ft_check_arg(t_all *all, int ac, char **av);
void			ft_input(t_all *all);
void			ft_take_input(t_all *all);
void			ft_take_texture(t_all *all, int i);
void			ft_take_res(t_all *all);
void			ft_take_color_or_texture(t_all *all, int i);
void			ft_map_to_list(t_all *all, t_list *list);
void			ft_list_to_matrix(t_all *all, t_list *list);
void			control_map(t_all *all);
void			control_constraits(t_all *all, int i, int j);
void			adjust_map(t_all *all);
/*
** Game part
*/
void			ft_game_manager(t_all *all);
void			ft_init_game(t_all *all);
void			ft_init_window(t_all *all);
void			ft_init_dir(t_all *all);
void			ft_init_keys(t_all *all);
int				ft_key_hit(int keycode, t_all *all);
int				ft_key_release(int keycode, t_all *all);
int				ft_key_register(t_all *all);
void			ft_draw_map(t_all *all);
void			ft_draw_first_map(t_all *all);
void			ft_get_player(t_all *all, int i, int j);
void			ft_draw_player(t_all *all, int color);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_draw_pixel_size(t_all *all, int color);

#endif
