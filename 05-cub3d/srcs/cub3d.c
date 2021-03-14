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
	if(ac == 2)
		ft_read_map(av[1]);
	else
	{
		ft_putendl_fd("No map found. Insert a valid map.", 2);
		return (1);
	}
}
