/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:55:54 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/17 13:24:48 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	cc;
	char			*str;

	cc = 0;
	str = (char *)s;
	while (cc < n)
	{
		if (str[cc] == (char)c)
			return (str + cc);
		cc++;
	}
	return (NULL);
}
