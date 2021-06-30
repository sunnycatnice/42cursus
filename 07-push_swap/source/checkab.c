/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:59:19 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/13 16:59:22 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checka(int *a, int n)
{
	int		i;

	i = 0;
	while (i < n - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	checkatwice(int *a, int *b, int *n, int size)
{
	int		i;
	int		min;

	i = 0;
	min = ft_findmin(a, size);
	while (i < size)
	{
		if (a[size - 1] == min)
		{
			rr(a, b, "rra", n);
			ft_putendl("rra");
			return (0);
		}
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	checkb(int *b, int n)
{
	int		i;

	i = 0;
	while (i < n - 1)
	{
		if (b[i] < b[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_findmin(int *a, int size)
{
	int	i;
	int	min;

	i = 0;
	min = a[0];
	while (i < size)
	{
		if (a[i] < min)
			min = a[i];
		i++;
	}
	return (min);
}
