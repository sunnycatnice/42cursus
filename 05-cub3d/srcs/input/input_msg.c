/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:29:37 by dmangola          #+#    #+#             */
/*   Updated: 2021/04/11 17:29:38 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	msg(int n)
{
	ft_green_color();
	printf("\n\u2714 ");
	if (n == 0)
		printf("Data export done!");
	else if (n == 1)
		printf("Map export done!");
	else if (n == 2)
		printf("Successful import!");
	else if (n == 3)
		printf("GGWP! Everything went alright\n\nProgram closed.");
	printf("\n\n");
	ft_reset_color();
}
