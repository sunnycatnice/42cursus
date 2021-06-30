/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:01:32 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/13 17:01:33 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	lolo(int *a, int n, int m, int *x)
{
	while (x[1] - x[0] != 1 && x[1] - x[0] != 0)
	{
		if (x[1] - x[0] != 1)
			m = m + (x[1] - x[0]);
		x[0] = 0;
		x[1] = 0;
		x[2] = 0;
		while (x[2] < n)
		{
			if (a[x[2]] < m)
				x[0]++;
			else
				x[1]++;
			x[2]++;
		}
	}
	return (m);
}

static void	lole(int *a, int *b, int *n, int i)
{
	if (i < (n[1] - n[0]) / 2)
	{
		while (i != 0)
		{
			r(a, b, "ra", n);
			ft_putendl("ra");
			i--;
		}
	}
	else
	{
		while (i != (n[1] - n[0]))
		{
			rr(a, b, "rra", n);
			ft_putendl("rra");
			i++;
		}
		i = 0;
	}
}

void	fstep(int *a, int *b, int *n)
{
	pa(a, b, "pa", n);
	ft_putendl("pa");
}

int	mid(int *a, int n)
{
	int		m;
	int		x[3];

	m = 0;
	x[0] = 0;
	x[1] = 0;
	x[2] = 0;
	while (x[2] < n)
	{
		m = m + a[x[2]];
		x[2]++;
	}
	m = m / x[2];
	x[2] = 0;
	while (x[2] < n)
	{
		if (a[x[2]] < m)
			x[0]++;
		else
			x[1]++;
		x[2]++;
	}
	m = lolo(a, n, m, x);
	return (m);
}

void	ft_upto_six(int *a, int *b, int *n)
{
	int		i;
	int		m;
	int		special_case;

	special_case = checkatwice(a, b, n, (n[1] - n[0]));
	if (!checka(a, n[1]))
	{
		m = mid(a, n[1]);
		i = 0;
		while (i < n[1] - n[0])
		{
			if (a[0] < m)
			{
				pa(a, b, "pb", n);
				ft_putendl("pb");
				i = 0;
			}
			if (a[i] < m)
				lole(a, b, n, i);
			i++;
		}
		ft_final(a, b, n);
	}
}
