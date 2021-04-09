/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:04:47 by dmangola          #+#    #+#             */
/*   Updated: 2021/04/09 14:04:51 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

static int		ft_atoi_res(t_mlx *mlx, const char *s, int *i, int pos)
{
	int	ret;

	ret = 0;
	ft_jump_spaces(s, i);
	if (!ft_isdigit(s[*i]))
		exit_manager(mlx, 12);
	while (ft_isdigit(s[*i]))
	{
		ret = ret * 10 + (s[*i] - '0');
		(*i)++;
	}
	if ((!pos && !ft_isspace(s[*i])) && (pos && (!ft_isspace(s[*i]) || s[*i])))
		exit_manager(mlx, 12);
	ft_jump_spaces(s, i);
	if ((!pos && !ft_isdigit(s[*i])) || (pos && s[*i]))
		exit_manager(mlx, 12);
	return (ret);
}

void			take_res(t_mlx *mlx, int i)
{
	int j;

	if (I_INPUT_DEFINED[i])
		exit_manager(mlx, 8);
	I_INPUT_DEFINED[i] = 1;
	j = 0;
	mlx->input.res_width = ft_atoi_res(mlx, mlx->tmp_input.line, &j, 0);
	mlx->input.res_height = ft_atoi_res(mlx, mlx->tmp_input.line, &j, 1);
	if (mlx->input.res_width < 1 || mlx->input.res_height < 1)
		exit_manager(mlx, 11);
	if (mlx->input.res_width > 2560)
		mlx->input.res_width = 2560;
	if (mlx->input.res_height > 1440)
		mlx->input.res_height = 1440;
}

