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

static int	ft_atoi_res(t_a *a, const char *s, int *i, int pos)
{
	int	ret;

	ret = 0;
	ft_jump_spaces(s, i);
	if (!ft_isdigit(s[*i]))
		ft_print_error(a, 12);
	while (ft_isdigit(s[*i]))
	{
		ret = ret * 10 + (s[*i] - '0');
		(*i)++;
	}
	if ((!pos && !ft_isspace(s[*i])) && (pos && (!ft_isspace(s[*i]) || s[*i])))
		ft_print_error(a, 12);
	ft_jump_spaces(s, i);
	if ((!pos && !ft_isdigit(s[*i])) || (pos && s[*i]))
		ft_print_error(a, 12);
	return (ret);
}

void	ft_take_res(t_a *a)
{
	int	j;

	j = 0;
	a->in.res_width = ft_atoi_res(a, a->map_in.line, &j, 0);
	a->in.res_height = ft_atoi_res(a, a->map_in.line, &j, 1);
	if (a->in.res_width < 1 || a->in.res_height < 1)
		ft_print_error(a, 11);
	if (a->in.res_width > 2560)
		a->in.res_width = 2560;
	if (a->in.res_height > 1440)
		a->in.res_height = 1440;
}
