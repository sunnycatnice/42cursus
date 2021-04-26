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

void	check_width(t_a *a)
{
	int	i;

	i = ft_strlen(a->map[a->map_in.map_lines]) + 1;
	if (i > a->in.map_width)
		a->in.map_width = i;
}
