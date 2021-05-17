/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:29:16 by dmangola          #+#    #+#             */
/*   Updated: 2021/05/17 12:29:38 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_three_nbrs(t_all *all, t_stack *a)
{
	ft_find_minmax_a(all, a);

	printf("tre numeri. il massimo e' %d e il minimo e' %d\n", a->max, a->min);
} 
