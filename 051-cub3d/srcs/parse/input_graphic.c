/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:50:39 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/29 13:50:42 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	ft_red_color(void)
{
	printf("\033[1;31m");
}

void	ft_green_color(void)
{
	printf("\033[0;32m");
}

void	ft_reset_color(void)
{
	printf("\033[0m");
}

void	ft_print_start(void)
{
	ft_green_color();
	printf("\n                          )(     \n");
	printf("   )\\     (   ( /(    ( /((()/(  \n");
	printf(" (((_)   ))\\  )\\())   )\\())/(_)) \n");
	printf(" )\\___  /((_)|((_)\\   ((_)\\(_))_  \n");
	printf("((/ __|(_)|( | |(_) |__ (_)|   \\ \n");
	printf(" | (__ | || || '_ \\  |_ \\  | |) |\n");
	printf("  \\___| \\_,_||_.__/ |___/  |___/ \n");
	ft_red_color();
	printf("              on fire              \n\n");
	ft_green_color();
	printf("Starting game...\n\n");
	ft_reset_color();
}
