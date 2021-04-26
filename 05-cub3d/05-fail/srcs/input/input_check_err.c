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

void	err_20(int error)
{
	if (error == 11)
		printf("*%d*: Wrong resolution", error);
	else if (error == 12)
		printf("*%d*: Wrong identation in resolution key", error);
	else if (error == 13)
		printf("*%d*: Wrong color number", error);
	else if (error == 14)
		printf("*%d*: Wrong identation in color key", error);
	else if (error == 15)
		printf("*%d*: Missing player", error);
	else if (error == 16)
		printf("*%d*: Map is open", error);
	else if (error == 17)
		printf("*%d*: Double player definition", error);
	else if (error == 18)
		printf("*%d*: Wrong square in map", error);
}

static void	err_10(int n)
{
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
	else if (n == 5)
		printf("%d: Error reading .cub file", n);
	else if (n == 6)
		printf("%d: Missing map", n);
	else if (n == 7)
		printf("%d: Wrong key name", n);
	else if (n == 8)
		printf("%d: Double key definition", n);
	else if (n == 9)
		printf("%d: Wrong identation in texture key", n);
	else if (n == 10)
		printf("%d: Can't find texture file. Was it written correctly?", n);
}

void	ft_check_err(int n)
{
	ft_red_color();
	printf("\nERROR N. ");
	if (n <= 10)
		err_10(n);
	else if (n <= 18)
		err_20(n);
	else
		printf("520: UNKNOWN ERROR.");
	printf("\n\n");
}
