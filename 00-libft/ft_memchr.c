/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:55:54 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/14 10:58:18 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	cc;
	char			*s;

	cc = 0;
	s = (char *)str;
	while (cc < n)
	{
		if (s[cc] == (char)c)
			return (s + cc);
		cc++;
	}
	return (NULL);
}
