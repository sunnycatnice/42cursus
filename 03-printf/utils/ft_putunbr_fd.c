/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:57:11 by dmangola          #+#    #+#             */
/*   Updated: 2021/02/09 13:57:23 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putunbr_fd(unsigned int n, int fd)
{
	char	print;

	if (!fd)
		return ;
	if (n >= 10)
	{
		ft_putunbr_fd(n / 10, fd);
		ft_putunbr_fd(n % 10, fd);
	}
	else
	{
		print = n + '0';
		write(fd, &print, 1);
	}
}
