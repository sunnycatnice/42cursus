/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:50:25 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/04 16:50:27 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_void_int_array(int len)
{
	int	*arr;
	int	index;

	index = 0;
	arr = malloc(len + 1 * sizeof(int));
	while (index < len)
	{
		arr[index] = -1;
		index += 1;
	}
	return (arr);
}

int	ft_int_arr_len(int *arr)
{
	int	index;

	index = 0;
	while (arr[index] > 0)
	{
		index++;
	}
	return (index);
}
