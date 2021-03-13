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

/*
** Including libft && minilibx
*/
# include "../libs/libft/libft.h"
# include "../libs/mlx/minilibx_mms_20200219/mlx.h"
# include "../libs/mlx/minilibx_opengl_20191021/mlx.h"

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_mlx
{
	void		*init;
	void		*win;
	t_data		data;
	
}				t_mlx;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				main(int ac, char **av);
char			**ft_read_map(char *av1);
int				put_pixel();
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
