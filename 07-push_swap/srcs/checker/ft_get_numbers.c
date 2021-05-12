/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:11:52 by dmangola          #+#    #+#             */
/*   Updated: 2021/05/07 13:11:54 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static int		*append_to_tab(t_a *a, char *s)
{
	char **tmp;
	char *new;
	int tmp_len;
	short i;

	if (!(tmp = ft_split(s, " ")))
		ft_perror("ERROR: not gnl free");
	tmp_len = ft_matrixlen(tmp);
	if(!(new = (int *)malloc((a->info_a.len + tmp_len) * sizeof(int))))
	{
		i = 0;
	}
	return 0;
}

void	ft_get_numbers(t_a *a, int ac, char **av)
{
	int	i;

	if (ac < 2)
		exit(1);
	i = 1;
	while (i < ac)
	{
		a->args.curr = arrange_nbrs(a, av[i]);
		i++;
	}
	i = 0;
	while (i < a->info_a.len)
	{
		if (a->args.curr[i] < a->args.min)
			a->args.min = a->args.curr[i];
		if (a->args.curr[i] > a->args.max)
			a->args.max = a->args.curr[i];
		save_nbr(a, a->args.curr[i]);
		i++;
	}
	a->args.len = a->info_a.len;
}