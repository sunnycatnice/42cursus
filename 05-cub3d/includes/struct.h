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

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct  s_flags
{
    short			save;
    short			finish;
	unsigned char	*screenshot;
}               t_flags;

typedef struct 	s_player 
{
	double 		posx;
	double		posy;
  	double 		dirx;
	double		diry;
  	double 		planex;
	double		planey;
	char		initial_direction;
}				t_player;

typedef	struct  	s_txt
{
	void			*img;
	unsigned int 	*data;
	int				bits_per_pixel;
    int				line_length;
    int				endian;
	int				width;
	int				height;
}					t_txt;

typedef struct		s_keycode
{
	short			w;
	short			a;
	short			s;
	short			d;
	short			ar;
	short			al;
	short			esc;
}					t_keycode;

typedef struct		s_dir
{
	int				no;
	int				so;
	int				ea;
	int				we;
}					t_dir;



typedef struct  s_mlx
{
    void        *mlx;
    void        *win;
}               t_mlx;

typedef struct		s_in
{
	int				defined[8];
	int				res_width;
	int				res_height;
	int				color_floor;
	int				color_ceiling;
	char			*txt_s;
	char			*txt_no;
	char			*txt_so;
	char			*txt_ea;
	char			*txt_we;
	char			*txt_fl;
	char			*txt_ce;
	int				map_width;
	int				map_height;
	int				player;
	int				save_flag;
	int				at_map_clone;
}					t_in;

typedef struct			s_map_in
{
	int				gnl_fd;
	int				gnl_first_space;
	int				tex_fd;
	int				map_lines;
	char			*line;
	char			*current_ide;
	char			*real_ide[8];
	char			**input;
	char			**new_;
}					t_map_in;

typedef struct		s_a
{
	char			**map;
	t_data			data;
	t_mlx			mlx;
	t_in			in;
	t_flags			flags;
	t_player		player;
	t_txt			txt;
	t_keycode		keycode;
	t_dir			dir;
	t_map_in		map_in;

}					t_a;

#endif