/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:43:03 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/04 16:43:06 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_copynu(t_numbers *dest, t_numbers *src)
{
	dest->number = src->number;
	dest->next = src->next;
	dest->position = src->position;
	dest->prev = src->prev;
}

t_numbers	*ft_last_elem(t_numbers *list)
{
	t_numbers	*curr_elem;

	if (!list)
		return (0);
	curr_elem = list;
	while (curr_elem->next)
		curr_elem = curr_elem->next;
	return (curr_elem);
}
