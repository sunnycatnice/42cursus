/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:32:00 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/16 17:32:06 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		n_to_p(int n)
{
	char s;

	s = '-';
	if (n < 0)
	{
		n = -n;
		write(1, &s, 1);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		d;
	int		r;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	n = n_to_p(n);
	r = (n % (10));
	d = (n / (10));
	if (d != 0)
	{
		ft_putnbr_fd(d, fd);
	}
	c = '0' + r;
	write(fd, &c, 1);
	return ;
}
