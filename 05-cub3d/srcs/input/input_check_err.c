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
	ft_red_color();
	printf("\nERROR N. ");
	if (n == 0)
		printf("%d: Malloc failed", n);
	else if (n == 1)
		printf("%d: Arguments number wrong", n);
	else if (n == 2)
		printf("%d: --save flag not recognised", n);
	else if (n == 3)
		printf("%d: .cub file not found", n);
	else if (n == 4)
		printf("%d: .cub file not opened", n);
	else if (n == 9)
		printf("%d: Wrong identation in texture key", n);
	else if (n == 10)
		printf("%d: Cannot open texture file", n);
}
