/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:23:09 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/19 17:23:11 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	engine_init(t_a *a)
{
	a->eng.pos_x = a->parse.spawn[0] + 0.5;
	a->eng.pos_y = a->parse.spawn[1] + 0.5;
	spawn_dir(cub);
	cub->spt = (t_sprite *)malloc(cub->parse.sp_num * sizeof(t_sprite));
	if (!cub->spt)
		ft_perror("Error\nMemory Allocation Failed");
	cub->eng.z_buff = (double *)malloc(cub->parse.x_res * sizeof(double));
	if (!cub->eng.z_buff)
		ft_perror("Error\nMemory Allocation Failed");
}
