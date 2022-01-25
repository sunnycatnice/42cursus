/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:17:47 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/18 22:18:27 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	idx;

	if (dest == 0 && src == 0)
		return (dest);
	idx = 0;
	d = (char *)dest;
	s = (char *)src;
	while (idx < n)
	{
		d[idx] = s[idx];
		idx++;
	}
	return (dest);
}
