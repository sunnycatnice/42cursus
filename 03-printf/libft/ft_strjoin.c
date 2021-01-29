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
