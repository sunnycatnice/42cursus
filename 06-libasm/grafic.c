/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:01:06 by dmangola          #+#    #+#             */
/*   Updated: 2021/04/19 20:01:07 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	printf("\n       (     (                   (       *    \n");
	printf("       )\\ )  )\\ )   (     (      )\\ )  (  `   \n");
	printf("      (()/( (()/( ( )\\    )\\    (()/(  )\\))(  \n");
	printf("       /(_)) /(_)))((_)((((_)(   /(_))((_)()\\ \n");
	printf("      (_))  (_)) ((_)_  )\\ _ )\\ (_))  (_()((_)\n");
	printf("      | |   |_ _| | _ ) (_)_\\(_)/ __| |  \\/  |\n");
	printf("      | |__  | |  | _ \\  / _ \\  \\__ \\ | |\\/| |\n");
	printf("      |____||___| |___/ /_/ \\_\\ |___/ |_|  |_|\n");
	ft_red_color();
	printf("                    on fire              \n\n");
	ft_green_color();
	printf("      Starting tests...\n\n");
	ft_reset_color();
}