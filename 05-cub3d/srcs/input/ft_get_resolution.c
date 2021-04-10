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

static int	ft_atoi_res(t_all *all, const char *s, int *i, int pos)
{
	int	ret;

	ret = 0;
	ft_jump_spaces(s, i);
	if (!ft_isdigit(s[*i]))
		ft_print_error(all, 12);
	while (ft_isdigit(s[*i]))
	{
		ret = ret * 10 + (s[*i] - '0');
		(*i)++;
	}
	if ((!pos && !ft_isspace(s[*i])) && (pos && (!ft_isspace(s[*i]) || s[*i])))
		ft_print_error(all, 12);
	ft_jump_spaces(s, i);
	if ((!pos && !ft_isdigit(s[*i])) || (pos && s[*i]))
		ft_print_error(all, 12);
	return (ret);
}

void	ft_take_res(t_all *all)
{
	int	j;

	j = 0;
	I_RES_WIDTH = ft_atoi_res(all, CP_GNL_LINE, &j, 0);
	I_RES_HEIGHT = ft_atoi_res(all, CP_GNL_LINE, &j, 1);
	if (I_RES_WIDTH < 1 || I_RES_HEIGHT < 1)
		ft_print_error(all, 11);
	if (I_RES_WIDTH > 2560)
		I_RES_WIDTH = 2560;
	if (I_RES_HEIGHT > 1440)
		I_RES_HEIGHT = 1440;
}
