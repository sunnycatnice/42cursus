/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:55:10 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/17 13:55:11 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_check_err(n)
{
	if (n == 0)
		printf("ERROR N. %d: Malloc failed\n", n);
	else if (n == 1)
		printf("ERROR N. %d: Arguments number wrong\n", n);
	else if (n == 2)
		printf("ERROR N. %d: --save flag not recognised\n", n);
	else if (n == 3)
		printf("ERROR N: %d: .cub file not found\n", n);
	else if (n == 4)
		printf("ERROR N: %d: .cub file not opened\n", n);
}
