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

static int	ft_atoi_color(t_all *all, const char *s, int *i, int color)
{
	int	ret;

	ret = 0;
	ft_jump_spaces(s, i);
	if (!ft_isdigit(s[*i]))
		ft_print_error(all, 14);
	while (ft_isdigit(s[*i]))
	{
		ret = ret * 10 + (s[*i] - '0');
		(*i)++;
	}
	ft_jump_spaces(s, i);
	if ((s[*i] == ',' && color != 2) || (color == 2 && !s[*i]))
		(*i)++;
	else
		ft_print_error(all, 14);
	return (ret);
}

static void	take_color(t_all *all, int i)
{
	int	red;
	int	green;
	int	blue;
	int	j;

	j = 0;
	red = ft_atoi_color(all, CP_GNL_LINE, &j, 0);
	green = ft_atoi_color(all, CP_GNL_LINE, &j, 1);
	blue = ft_atoi_color(all, CP_GNL_LINE, &j, 2);
	if (red < 0 || red > 255 || green < 0 || green > 255
		|| blue < 0 || blue > 255)
		ft_print_error(all, 13);
	if (i == 6)
		I_COLOR_CEILING = (red * 16 * 16 * 16 * 16) + (green * 16 * 16) + blue;
	else if (i == 7)
		I_COLOR_FLOOR = (red * 16 * 16 * 16 * 16) + (green * 16 * 16) + blue;
}

static void	take_z_texture(t_all *all, int i)
{
	int	exit;

	CPP_INPUT = ft_split(*CPP_INPUT, " \t\v\r\f");
	if (!CPP_INPUT)
		ft_print_error(all, 0);
	CP_TEX_FD = open(*CPP_INPUT, O_RDONLY);
	if (!CPP_INPUT[0] || CPP_INPUT[1] || (CP_TEX_FD < 0))
	{
		if (CP_TEX_FD > -1)
			exit = 9;
		else
			exit = 10;
		ft_print_error(all, exit);
	}
	if (i == 6)
		all->input.texture_ceiling = CPP_INPUT[0];
	else if (i == 7)
		all->input.texture_floor = CPP_INPUT[0];
	free(CPP_INPUT);
	CPP_INPUT = 0;
	close(CP_TEX_FD);
	CP_TEX_FD = -1;
}

void	ft_take_color_or_texture(t_all *all, int i)
{
	int	j;

	j = 0;
	CP_TEX_FD = 0;
	ft_jump_spaces(CP_GNL_LINE, &j);
	if (CP_GNL_LINE[j] == '.')
		take_z_texture(all, i);
	else if (ft_isdigit(CP_GNL_LINE[j]))
		take_color(all, i);
	else
		ft_print_error(all, 14);
}
