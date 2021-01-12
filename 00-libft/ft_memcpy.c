/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:24:01 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/12 15:28:33 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned int	c;
	char			*d;
	char			*s;

	d = (char *)dst;
	s = (char *)src;
	c = 0;
	while (c < n)
		d[c++] = s[c];
	return (dst);
}
