/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:58:23 by dmangola          #+#    #+#             */
/*   Updated: 2021/09/02 16:58:25 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	ft_printerr(int err)
{
	if (err == 0)
		ft_putstr_star_fd(ERR_0, 2);
	else if (err == 1)
		ft_putstr_star_fd(ERR_1, 2);
	else if (err == 2)
		ft_putstr_star_fd(ERR_2, 2);
	else if (err == 3)
		ft_putstr_star_fd(ERR_3, 2);
	else if (err == 4)
		ft_putstr_star_fd(ERR_4, 2);
	else if (err == 5)
		ft_putstr_star_fd(ERR_5, 2);
	else if (err == 6)
		ft_putstr_star_fd(ERR_6, 2);
	else if (err == 7)
		ft_putstr_star_fd(ERR_7, 2);
	else if (err == 8)
		ft_putstr_star_fd(ERR_8, 2);
	exit (1);
}

void	ft_printstars(char *str)
{
	short	i;
	short	len;

	i = -1;
	len = ft_strlen(str) - 3;
	ft_putstr_fd("\033[0;31m", 2);
	while (++i < len)
		ft_putchar_fd('*', 2);
	ft_putstr_fd("\033[0m\n", 2);
}
