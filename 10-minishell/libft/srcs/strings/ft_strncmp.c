/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:09:20 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/19 18:04:36 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	x;
	unsigned char	y;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			x = (unsigned char)s1[i];
			y = (unsigned char)s2[i];
			return (x - y);
		}
		i++;
	}
	return (0);
}
