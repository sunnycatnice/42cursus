/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_print_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:51:53 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/16 15:51:54 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_print_error(t_all *all, int n)
{
	check_err(n);
	if (I_GNL_FD > -1)
		get_next_line_free(all);
	//all_input_free(all);
	all_map_input_free(all);
	exit(1);
}
