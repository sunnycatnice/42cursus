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

static void	finish(t_all *all)
{
	free(CPP_INPUT);
	CPP_INPUT = 0;
	close(CP_TEX_FD);
	CP_TEX_FD = -1;
}

static void	ft_take_texture_1(t_all *all, int i)
{
	if (i == 0)
		CP_TEXT_S = CPP_INPUT[0];
	else if (i == 1)
		CP_TEXT_NO = CPP_INPUT[0];
	else if (i == 2)
		CP_TEXT_SO = CPP_INPUT[0];
	else if (i == 3)
		CP_TEXT_WE = CPP_INPUT[0];
	else if (i == 4)
		CP_TEXT_EA = CPP_INPUT[0];
}

void	ft_take_texture(t_all *all, int i)
{
	int	exit;

	CP_TEX_FD = 0;
	if (I_INPUT_DEFINED[i])
		ft_print_error(all, 8);
	I_INPUT_DEFINED[i] = 1;
	CPP_INPUT = ft_split(CP_GNL_LINE, " \t\v\r\f");
	if (!CPP_INPUT)
		ft_print_error(all, 0);
	CP_TEX_FD = open(CPP_INPUT[0], O_RDONLY);
	if (!CPP_INPUT[0] || CPP_INPUT[1] || (CP_TEX_FD) < 0)
	{
		if (CP_TEX_FD > -1)
			exit = 9;
		else
			exit = 10;
		ft_print_error(all, exit);
	}
	ft_take_texture_1(all, i);
	finish(all);
}
