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

typedef struct			s_map_input
{
	int				gnl_fd;
	int				tex_fd;
	char			*line;
	char			*ide;
	char			*identifiers[8];
	char			**input;
	char			**new_;
}					t_map_input;

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_all
{
	void			*init;
	void			*win;
	t_data			data;
	t_map_input		map_input;

}					t_all;

#endif