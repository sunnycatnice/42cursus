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

int			is_line(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t index;

	index = 0;
	while (src && index < n)
	{
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dst);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	dim_s1;
	size_t	dim_s2;
	size_t	tot_len;

	if (!s1 && !s2)
		return (0);
	dim_s1 = ft_strlen((char *)s1);
	dim_s2 = ft_strlen((char *)s2);
	tot_len = dim_s1 + dim_s2 + 1;
	if (!(strjoin = malloc(tot_len * sizeof(char))))
		return (NULL);
	ft_memcpy(strjoin, s1, dim_s1);
	ft_memcpy(strjoin + dim_s1, s2, dim_s2);
	strjoin[tot_len - 1] = '\0';
	free((char *)s1);
	return (strjoin);
}

/*char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		lung1;
	int		lung2;
	char	*str;

	if (s1 && s2)
	{
		lung1 = ft_strlen((char *)s1);
		lung2 = ft_strlen((char *)s2);
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
		free((char *)s1);
		return (str);
	}
	return (NULL);
} */

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if(!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}