/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:52:54 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/05 16:52:55 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int ac, char **av)
{
	t_all	all;

	init_map_input(&all);
	check_arg(&all, ac, av);
	if (ac == 2)
		all.input.map = ft_read_map(&all, av[1]);
	ft_get_window(&all);
}
