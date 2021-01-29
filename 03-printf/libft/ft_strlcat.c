/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:44:27 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/15 13:21:37 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;

	i = 0;
	while (*dst && i < dstsize)
	{
		++i;
		++dst;
	}
	while (*src && i + 1 < dstsize)
	{
		*dst = *src;
		++dst;
		++src;
		++i;
	}
	if (i < dstsize)
		*dst = 0;
	while (*src)
	{
		++i;
		++src;
	}
	return (i);
}
