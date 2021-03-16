/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:24:42 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/16 14:24:44 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	find_cub_file(char *s)
{
	short len;
	short res;

	len = ft_strlen(s);
	if (len > 0)
	{
		res = !(len < 5) ?: 0;
		res = !(s[len - 4] != '.') ?: 0;
		res = !(s[len - 3] != 'c') ?: 0;
		res = !(s[len - 2] != 'u') ?: 0;
		res = !(s[len - 1] != 'b') ?: 0;
		return (res);
	}
	res = 1;
	return (res);
}

void		check_arg(t_all *all, int ac, char **av)
{
	if(ac == 2)
		ft_read_map(all, av[1]);
	else
	{
		if (ac == 3)
		{
			if(ft_strncmp(av[2], "--save", sizeof(av[2] + 7)))
				print_error(all, (ac != 2) ? 1 : 2);
			all->input.save_flag;
		}
		if (!find_cub_file(av[1]))
			print_error(all, 2);
	}
}