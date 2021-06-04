/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:46:24 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/04 16:46:25 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_max_on_head_b(t_numbers **stack_b)
{
	t_numbers	*max;

	max = ft_max_node_in_stack(*stack_b);
	ft_node_distances_from_head(max, &max->dist_head);
	if (max->dist_head.r < max->dist_head.rr)
	{
		while (max->dist_head.r > 0)
		{
			ft_do_move(NULL, stack_b, "rb");
			max->dist_head.r -= 1;
		}
	}
	else
	{
		while (max->dist_head.rr > 0)
		{
			ft_do_move(NULL, stack_b, "rrb");
			max->dist_head.rr -= 1;
		}
	}
}

void	ft_min_on_head(t_numbers **stack_a)
{
	t_numbers	*j_i_c;

	j_i_c = ft_min_node(*stack_a);
	ft_node_distances_from_head(j_i_c, &j_i_c->dist_head);
	while (*stack_a != j_i_c)
	{
		if (j_i_c->dist_head.r < j_i_c->dist_head.rr)
			ft_do_move(stack_a, NULL, "ra");
		else
			ft_do_move(stack_a, NULL, "rra");
	}
}
