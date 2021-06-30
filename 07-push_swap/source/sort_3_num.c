/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:01:21 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/13 17:01:22 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	do_rr(int *a, int *b, int *n, char *s)
{
	if (ft_strequ(s, "rra"))
	{
		rr(a, b, "rra", n);
		ft_putendl("rra");
	}
	else if (ft_strequ(s, "rrb"))
	{
		rr(a, b, "rrb", n);
		ft_putendl("rrb");
	}
}

void	ft_upto_three(int *a, int *b, int *n)
{
	while (!checka(a, n[1] - n[0]))
	{
		if (a[1] > a[0] && a[2] > a[0] && a[1] > a[2] && n[1] - n[0] == 3)
		{
			s(a, b, "sa", n);
			ft_putendl("sa");
			r(a, b, "ra", n);
			ft_putendl("ra");
		}
		else if (a[1] < a[0] && a[2] > a[0]
			&& a[1] < a[2] && n[1] - n[0] == 3)
		{
			s(a, b, "sa", n);
			ft_putendl("sa");
		}
		else if (((a[0] > a[1] && a[1] > a[2])
				|| (a[1] < a[0] && a[1] < a[2]
					&& a[2] < a[0])) && n[1] - n[0] == 3)
		{
			r(a, b, "ra", n);
			ft_putendl("ra");
		}
		else
			do_rr(a, b, n, "rra");
	}
}

void	ft_upto_three_b(int *a, int *b, int *n)
{
	while (!checkb(b, n[0]))
	{
		if (b[1] > b[0] && b[2] > b[0] && b[1] < b[2] && n[0] == 3)
		{
			s(a, b, "sb", n);
			ft_putendl("sb");
			rr(a, b, "rrb", n);
			ft_putendl("rrb");
		}
		else if (b[1] > b[0] && b[2] < b[0] && b[1] > b[2] && n[0] == 3)
		{
			s(a, b, "sb", n);
			ft_putendl("sb");
		}
		else if (b[0] < b[1] && b[1] > b[2] && b[0] < b[2] && n[0] == 3)
		{
			r(a, b, "rb", n);
			ft_putendl("rb");
		}
		else
			do_rr(a, b, n, "rrb");
	}
}

void	ft_final(int *a, int *b, int *n)
{
	ft_upto_three(a, b, n);
	ft_upto_three_b(a, b, n);
	while (n[0] != 0)
		fstep(a, b, n);
}

void	check_letter_innumber(char **tmp)
{
	int	j;
	int	n;

	j = 0;
	n = 0;
	while (tmp[j])
	{
		n = 0;
		while (tmp[j][n])
		{
			if (!(ft_isdigit(tmp[j][n])))
			{
				ft_putendl("Error");
				exit (0);
			}
			n++;
		}
		j++;
	}
}
