/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:01:18 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/12 12:24:20 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	m;
	unsigned int	i;

	str = (unsigned char *)b;
	m = (unsigned char)c;
	i = 0;
	while (i < len)
		str[i++] = m;
	return (b);
}
