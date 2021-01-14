/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:08:46 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/14 17:00:59 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	i;

	i = 0;
	if (count == 0 || size == 0)
		return (NULL);
	res = malloc(size * count);
	while (i <= count)
	{
		((char*)res)[i] = 0;
		i++;
	}
	return (res);
}
