/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 16:59:47 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/13 16:59:50 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	dub_check(int ac, int *num)
{
	int		i;
	int		j;

	j = 0;
	if (ac > 1)
	{
		while (++j < ac)
		{
			i = 0;
			while (i < j)
			{
				if (num[i] == num[j])
				{
					ft_putendl("Error");
					exit(0);
				}
				i++;
			}
		}
	}
}

void	place1(int *n, int *a, char **av)
{
	a[n[1] - 1] = ft_atoi(av[n[2]]);
	if ((a[n[1] - 1])
		|| ft_strequ(av[n[2]], "0"))
	{
	}
	else
	{
		ft_putendl("Error");
		exit(0);
	}
}

void	place2(int *n, int *a, char **av)
{
	int		i;

	i = 0;
	while (i < n[0])
	{
		a[n[2]] = ft_atoi(av[i]);
		if (a[n[2]] || ft_strequ(av[i], "0"))
		{
			n[2]++;
			i++;
		}
		else
		{
			ft_putendl("Error");
			exit(0);
		}
	}
}

void	erpl2(int *a, int *x, char **tmp)
{
	place2(x, a, tmp);
	dub_check(x[1], a);
}

void	erpl1(int *a, int *x, char **tmp)
{
	int	j;
	int	n;

	j = 1;
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
	place1(x, a, tmp);
	dub_check(x[1], a);
}
