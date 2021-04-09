/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:03:50 by dmangola          #+#    #+#             */
/*   Updated: 2021/04/09 14:04:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/input.h"

void	take_texture(t_mlx *mlx, int i)
{
	mlx->tmp_input.tex_fd = 0;
	if (I_INPUT_DEFINED[i])
		exit_manager(mlx, 8);
	I_INPUT_DEFINED[i] = 1;
	if (!(mlx->tmp_input.input = ft_split(mlx->tmp_input.line, " \t\v\r\f")))
		exit_manager(mlx, 0);
	if (!mlx->tmp_input.input[0] || mlx->tmp_input.input[1] ||
	((mlx->tmp_input.tex_fd = open(mlx->tmp_input.input[0], O_RDONLY)) < 0))
		exit_manager(mlx, (mlx->tmp_input.tex_fd > -1 ? 9 : 10));
	if (i == 0)
		mlx->input.texture_s = mlx->tmp_input.input[0];
	else if (i == 1)
		mlx->input.texture_no = mlx->tmp_input.input[0];
	else if (i == 2)
		mlx->input.texture_so = mlx->tmp_input.input[0];
	else if (i == 3)
		mlx->input.texture_we = mlx->tmp_input.input[0];
	else if (i == 4)
		mlx->input.texture_ea = mlx->tmp_input.input[0];
	free(mlx->tmp_input.input);
	mlx->tmp_input.input = 0;
	close(mlx->tmp_input.tex_fd);
	mlx->tmp_input.tex_fd = -1;
}

