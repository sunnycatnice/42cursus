/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_col_tex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:05:24 by dmangola          #+#    #+#             */
/*   Updated: 2021/04/09 14:05:28 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_atoi_color(t_a *a, const char *s, int *i, int color)
{
	int	ret;

	ret = 0;
	ft_jump_spaces(s, i);
	if (!ft_isdigit(s[*i]))
		ft_print_error(a, 14);
	while (ft_isdigit(s[*i]))
	{
		ret = ret * 10 + (s[*i] - '0');
		(*i)++;
	}
	ft_jump_spaces(s, i);
	if ((s[*i] == ',' && color != 2) || (color == 2 && !s[*i]))
		(*i)++;
	else
		ft_print_error(a, 14);
	return (ret);
}

static void	take_color(t_a *a, int i)
{
	int	red;
	int	green;
	int	blue;
	int	j;

	j = 0;
	red = ft_atoi_color(a, a->map_in.line, &j, 0);
	green = ft_atoi_color(a, a->map_in.line, &j, 1);
	blue = ft_atoi_color(a, a->map_in.line, &j, 2);
	if (red < 0 || red > 255 || green < 0 || green > 255
		|| blue < 0 || blue > 255)
		ft_print_error(a, 13);
	if (i == 6)
		a->in.color_ceiling = (red * 16 * 16 * 16 * 16) + (green * 16 * 16) + blue;
	else if (i == 7)
		a->in.color_floor = (red * 16 * 16 * 16 * 16) + (green * 16 * 16) + blue;
}

static void	take_z_texture(t_a *a, int i)
{
	int	exit;

	 a->map_in.input = ft_split(* a->map_in.input, " \t\v\r\f");
	if (!a->map_in.input)
		ft_print_error(a, 0);
	a->map_in.tex_fd = open(* a->map_in.input, O_RDONLY);
	if (! a->map_in.input[0] ||  a->map_in.input[1] || (a->map_in.tex_fd < 0))
	{
		if (CP_TEX_FD > -1)
			exit = 9;
		else
			exit = 10;
		ft_print_error(a, exit);
	}
	if (i == 6)
		a->in.txt_ce =  a->map_in.input[0];
	else if (i == 7)
		a->in.txt_fl =  a->map_in.input[0];
	free( a->map_in.input);
	 a->map_in.input = 0;
	close(a->map_in.tex_fd);
	a->map_in.tex_fd = -1;
}

void	ft_take_color_or_texture(t_a *a, int i)
{
	int	j;

	j = 0;
	a->map_in.tex_fd = 0;
	ft_jump_spaces(a->map_in.line, &j);
	if (a->map_in.line[j] == '.')
		take_z_texture(a, i);
	else if (ft_isdigit(a->map_in.line[j]))
		take_color(a, i);
	else
		ft_print_error(a, 14);
}
