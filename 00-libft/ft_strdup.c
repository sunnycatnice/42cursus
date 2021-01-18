/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:36:29 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/17 10:00:27 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*new;
	size_t		size;
	size_t		s_size;

	size = 0;
	while (s1[size])
		++size;
	if (!(new = (void *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strlcpy(new, s1, (s_size = ft_strlen(s1)) + 1);
	new[s_size] = '\0';
	return (new);
}
