/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:45:51 by dmangola          #+#    #+#             */
/*   Updated: 2021/04/13 13:46:38 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_width(t_all *all)
{
	int i;

	i = ft_strlen(CPP_MAP[I_MAP_LINES]) + 1;
	if (i > I_MAP_WIDTH)
		I_MAP_WIDTH = i;
}
