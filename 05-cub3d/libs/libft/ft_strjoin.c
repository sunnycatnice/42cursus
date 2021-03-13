/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:06:38 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/16 10:39:29 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len_s1;
	size_t	len_s2;
	size_t	total_len;

	if (!s1 && !s2)
		return (0);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	total_len = len_s1 + len_s2 + 1;
	if (!(strjoin = malloc(total_len * sizeof(char))))
		return (NULL);
	ft_memcpy(strjoin, s1, len_s1);
	ft_memcpy(strjoin + len_s1, s2, len_s2);
	strjoin[total_len - 1] = '\0';
	free((char *)s1);
	return (strjoin);
}
