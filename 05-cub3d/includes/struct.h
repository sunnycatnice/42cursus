 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:05:28 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/15 17:05:30 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "../libs/libft/libft.h"

typedef	struct s_point
{
	int				x;
	int				y;
}				t_point;

typedef struct		s_player
{
	float			pos_x;
	float			pos_y;
	double			speed;
	float			dir;
	double			rot_speed;
}					t_player;

typedef struct		s_keys
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				esc;
}					t_keys;

typedef struct		s_dir
{
	int				no;
	int				so;
	int				ea;
	int				we;
}					t_dir;

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct  s_mlx {
    void        *mlx;
    void        *win;
}               t_mlx;

typedef struct		s_input
{
	int				defined[8];
	int				res_width;
	int				res_height;
	int				color_floor;
	int				color_ceiling;
	char			*texture_s;
	char			*texture_no;
	char			*texture_so;
	char			*texture_we;
	char			*texture_ea;
	char			*texture_floor;
	char			*texture_ceiling;
	int				map_width;
	int				map_height;
	int				player;
	int				player_x;
	int				player_y;
	int				save_flag;
}					t_input;

typedef struct			s_map_input
{
	int				gnl_fd;
	int				tex_fd;
	int				map_lines;
	char			*line;
	char			*current_ide;
	char			*real_ide[8];
	char			**input;
	char			**new_;
}					t_map_input;

typedef struct		s_all
{
	char			**map;
	t_input			input;
	t_mlx			mlx;
	t_data			data;
	t_player		player;
	t_keys			keys;
	t_dir			dir;
	t_map_input		map_input;
	t_point			point;

}					t_all;

#endif