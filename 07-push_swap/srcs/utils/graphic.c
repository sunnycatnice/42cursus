/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:55:22 by dmangola          #+#    #+#             */
/*   Updated: 2021/05/07 11:55:24 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

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

void	ft_print_start_ck(void)
{
	ft_green_color();
	printf("\n (           (        )       (                       (    \n");
	printf(" )\\ )        )\\ )  ( /(       )\\ )  (  (       (      )\\ ) \n");
	printf("(()/(    (  (()/(  )\\())     (()/(  )\\))(   '  )\\    (()/( \n");
	printf(" /(_))   )\\  /(_))((_)\\       /(_))((_)()\\ )((((_)(   /(_))\n");
	printf("(_))  _ ((_)(_))   _((_)     (_))  _(())\\_)())\\ _ )\\ (_))  \n");
	printf("| _ \\| | | |/ __| | || |     / __| \\ \\((_)/ /(_)_\\(_)| _ \\ \n");
	printf("|  _/| |_| |\\__ \\ | __ |     \\__ \\  \\ \\/\\/ /  / _ \\  |  _/ \n");
	printf("|_|   \\___/ |___/ |_||_|_____|___/   \\_/\\_/  /_/ \\_\\ |_|   \n");
	printf("                       |_____|                             \n");
	ft_red_color();
	printf("              on fire              \n\n");
	ft_green_color();
	printf("Starting CHECKER...\n\n");
	ft_reset_color();
}

void	ft_print_start_ps(void)
{
	ft_green_color();
	printf("\n (           (        )       (                       (    \n");
	printf(" )\\ )        )\\ )  ( /(       )\\ )  (  (       (      )\\ ) \n");
	printf("(()/(    (  (()/(  )\\())     (()/(  )\\))(   '  )\\    (()/( \n");
	printf(" /(_))   )\\  /(_))((_)\\       /(_))((_)()\\ )((((_)(   /(_))\n");
	printf("(_))  _ ((_)(_))   _((_)     (_))  _(())\\_)())\\ _ )\\ (_))  \n");
	printf("| _ \\| | | |/ __| | || |     / __| \\ \\((_)/ /(_)_\\(_)| _ \\ \n");
	printf("|  _/| |_| |\\__ \\ | __ |     \\__ \\  \\ \\/\\/ /  / _ \\  |  _/ \n");
	printf("|_|   \\___/ |___/ |_||_|_____|___/   \\_/\\_/  /_/ \\_\\ |_|   \n");
	printf("                       |_____|                             \n");
	ft_red_color();
	printf("              on fire              \n\n");
	ft_green_color();
	printf("Starting PUSH_SWAP...\n\n");
	ft_reset_color();
}