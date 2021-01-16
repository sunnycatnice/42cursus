/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:29:49 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/16 17:29:54 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_itoa_len(int n)
{
	long int	res;

	res = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char		*res;
	long int	n2;
	int			c;
	int			sig;

	c = 0;
	sig = 1;
	if ((n2 = n) < 0)
	{
		n2 *= (sig *= -1);
		c += 1;
	}
	c += ft_itoa_len(n2);
	if (!(res = (char *)malloc(sizeof(char) * (c + 1))))
		return (NULL);
	res[c] = '\0';
	while (--c != -1)
	{
		res[c] = (char)(48 + (n2 % 10));
		n2 /= 10;
	}
	if (sig == -1)
		res[0] = '-';
	return (res);
}
