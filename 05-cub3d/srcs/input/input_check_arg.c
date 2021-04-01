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
	short	len;

	len = ft_strlen(s);
	if (len < 5)
		return (0);
	if (s[len - 4] != '.')
		return (0);
	if (s[len - 3] != 'c')
		return (0);
	if (s[len - 2] != 'u')
		return (0);
	if (s[len - 1] != 'b')
		return (0);
	return (1);
}

void	ft_check_arg(t_all *all, int ac, char **av)
{
	short	err;

	if (ac != 2)
	{
		if (ac == 3)
		{
			if (ft_strncmp(av[2], "--save", sizeof(av[2] + 7)))
			{
				if (ac != 2)
					err = 1;
				else
					err = 2;
				ft_print_error(all, err);
			}
			all->input.save_flag = 1;
		}
		else
			ft_print_error(all, 3);
	}
	if (!find_cub_file(av[1]))
		ft_print_error(all, 3);
	I_GNL_FD = open(av[1], O_RDONLY);
	if (I_GNL_FD < 0)
		ft_print_error(all, 4);
}
