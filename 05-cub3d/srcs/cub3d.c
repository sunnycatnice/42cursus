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

int	main(int ac, char **av)
{
	t_all	all;

	ft_init_map_input(&all);
	ft_check_arg(&all, ac, av);
	ft_input_manager(&all);
	ft_game_manager(&all);
	return (0);
}
