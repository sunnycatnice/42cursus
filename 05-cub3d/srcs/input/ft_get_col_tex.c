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

static int		ft_atoi_color(t_mlx *mlx, const char *s, int *i, int color)
{
	int ret;

	ret = 0;
	ft_jump_spaces(s, i);
	if (!ft_isdigit(s[*i]))
		exit_manager(mlx, 14);
	while (ft_isdigit(s[*i]))
	{
		ret = ret * 10 + (s[*i] - '0');
		(*i)++;
	}
	ft_jump_spaces(s, i);
	if ((s[*i] == ',' && color != 2) || (color == 2 && !s[*i]))
		(*i)++;
	else
		exit_manager(mlx, 14);
	return (ret);
}

static void		take_color(t_mlx *mlx, int i)
{
	int	red;
	int	green;
	int	blue;
	int	j;

	j = 0;
	red = ft_atoi_color(mlx, mlx->tmp_input.line, &j, 0);
	green = ft_atoi_color(mlx, mlx->tmp_input.line, &j, 1);
	blue = ft_atoi_color(mlx, mlx->tmp_input.line, &j, 2);
	if (red < 0 || red > 255 || green < 0 || green > 255
	|| blue < 0 || blue > 255)
		exit_manager(mlx, 13);
	if (i == 6)
		mlx->input.color_ceiling = (red * 16 * 16 * 16 * 16) +
		(green * 16 * 16) + blue;
	else if (i == 7)
		mlx->input.color_floor = (red * 16 * 16 * 16 * 16) +
		(green * 16 * 16) + blue;
}

static void		take_z_texture(t_mlx *mlx, int i)
{
	if (!(mlx->tmp_input.input = ft_split(mlx->tmp_input.line, " \t\v\r\f")))
		exit_manager(mlx, 0);
	if (!mlx->tmp_input.input[0] || mlx->tmp_input.input[1] ||
	((mlx->tmp_input.tex_fd = open(mlx->tmp_input.input[0], O_RDONLY)) < 0))
		exit_manager(mlx, (mlx->tmp_input.tex_fd > -1 ? 9 : 10));
	if (i == 6)
		mlx->input.texture_ceiling = mlx->tmp_input.input[0];
	else if (i == 7)
		mlx->input.texture_floor = mlx->tmp_input.input[0];
	free(mlx->tmp_input.input);
	mlx->tmp_input.input = 0;
	close(mlx->tmp_input.tex_fd);
	mlx->tmp_input.tex_fd = -1;
}

void			take_color_or_texture(t_mlx *mlx, int i)
{
	int j;

	j = 0;
	mlx->tmp_input.tex_fd = 0;
	if (I_INPUT_DEFINED[i])
		exit_manager(mlx, 8);
	I_INPUT_DEFINED[i] = 1;
	ft_jump_spaces(mlx->tmp_input.line, &j);
	if (mlx->tmp_input.line[j] == '.')
		take_z_texture(mlx, i);
	else if (ft_isdigit(mlx->tmp_input.line[j]))
		take_color(mlx, i);
	else
		exit_manager(mlx, 14);
}

