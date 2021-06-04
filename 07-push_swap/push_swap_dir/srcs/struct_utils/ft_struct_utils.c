/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:49:55 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/04 16:49:56 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dist_clear(t_distances *dist)
{
	dist->r = -1;
	dist->rr = -1;
}

int	ft_is_dist(t_distances *dist)
{
	if (dist->r == -1 || dist->rr == -1)
		return (0);
	return (1);
}
