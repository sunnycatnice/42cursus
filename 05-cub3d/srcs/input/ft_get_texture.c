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

#include "../../includes/cub3d.h"

static void	finish(t_a *a)
{
	free(a->map_in.input);
	a->map_in.input = 0;
	close(a->map_in.tex_fd);
	a->map_in.tex_fd = -1;
}

static void	ft_take_texture_1(t_a *a, int i)
{
	if (i == 0)
		a->in.txt_s = a->map_in.input[0];
	else if (i == 1)
		a->in.txt_no = a->map_in.input[0];
	else if (i == 2)
		a->in.txt_so = a->map_in.input[0];
	else if (i == 3)
		a->in.txt_we = a->map_in.input[0];
	else if (i == 4)
		a->in.txt_ea = a->map_in.input[0];
}

void	ft_take_texture(t_a *a, int i)
{
	int	exit;

	a->map_in.tex_fd = 0;
	if (I_INPUT_DEFINED[i])
		ft_print_error(a, 8);
	I_INPUT_DEFINED[i] = 1;
	a->map_in.input = ft_split(a->map_in.line, " \t\v\r\f");
	if (!a->map_in.input)
		ft_print_error(a, 0);
	a->map_in.tex_fd = open(a->map_in.input[0], O_RDONLY);
	if (!a->map_in.input[0] || a->map_in.input[1] || (a->map_in.tex_fd) < 0)
	{
		if (a->map_in.tex_fd > -1)
			exit = 9;
		else
			exit = 10;
		ft_print_error(a, exit);
	}
	ft_take_texture_1(a, i);
	finish(a);
}
