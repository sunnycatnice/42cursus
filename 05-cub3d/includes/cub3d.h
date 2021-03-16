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
# include "../libs/mlx/minilibx_opengl_20191021/mlx.h"
/*
** Including all header files
*/
# include "define.h"
# include "struct.h"

int				main(int ac, char **av);
void			check_arg(t_all *all, int ac, char **av);
void			print_error(t_all *all, int n);
char			**ft_read_map(t_all *all, char *av1);
char			**ft_make_map(t_list **list, int size);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
