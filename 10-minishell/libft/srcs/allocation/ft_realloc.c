/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:56:44 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/18 22:15:03 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char **ptr, char c)
{
	char	*ret;
	int		size;

	if (!ptr)
		return (0);
	size = ft_strlen(*ptr);
	ret = (char *)ft_calloc_internet(sizeof(char), size + 2);
	if (!ret)
		return (0);
	ft_memcpy(ret, *ptr, size);
	ret[size] = c;
	ft_free(*ptr);
	*ptr = ret;
	return (ret);
}
