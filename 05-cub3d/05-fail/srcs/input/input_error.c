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

void	ft_print_error(t_a *a, int n)
{
	ft_check_err(n);
	if (a->map_in.gnl_fd > -1)
		ft_get_next_line_free(a);
	ft_all_map_input_free(a);
	exit(1);
}
