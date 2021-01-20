/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:19:21 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/18 17:19:22 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		lung1;
	int		lung2;
	char	*str;

	if (s1 && s2)
	{
		lung1 = ft_strlen(s1);
		lung2 = ft_strlen(s2);
		str = (char*)malloc(sizeof(char) * (lung1 + lung2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[lung1] = s2[i];
			lung1++;
		}
		str[lung1] = '\0';
		return (str);
	}
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}