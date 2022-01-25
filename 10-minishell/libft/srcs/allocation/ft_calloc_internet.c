/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_internet.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:42:15 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/18 22:14:16 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc_internet(size_t size, size_t count)
{
	void		*addr;

	addr = malloc(size * count);
	if (!addr)
		return (0);
	ft_memset(addr, 0, size * count);
	return (addr);
}
