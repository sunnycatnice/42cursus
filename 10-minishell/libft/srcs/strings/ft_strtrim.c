/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:38:46 by bde-luca          #+#    #+#             */
/*   Updated: 2022/04/19 14:58:15 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> 

//static int	is_in_charset(char c, char *charset)
//{
//	size_t	i;
//
//	i = 0;
//	while (charset[i])
//	{
//		if (charset[i] == c)
//			return (1);
//		i++;
//	}
//	return (0);
//}
//
//char	*ft_strtrim(const char *s1, const char *s2)
//{
//	char	*s;
//	size_t	start;
//	size_t	end;
//	size_t	i;
//
//	if (!s1)
//		return (NULL);
//	start = 0;
//	end = ft_strlen((char *)s1);
//	while (s1[start] && is_in_charset(s1[start], (char *)s2))
//		start++;
//	while (end >= start && (is_in_charset(s1[end], (char *)s2)))
//		end--;
//	s = (char *)malloc((end - start + 1) * sizeof(char));
//	if (!s)
//		return (NULL);
//	i = 0;
//	while (start < end)
//		s[i++] = s1[start++];
//	s[i] = '\0';
//	return (s);
//}
static int	ft_isset(char const str, char const *set)
{
	unsigned long int	i;

	i = -1;
	while (set[++i] != str && set[i])
		;
	if (set[i] == str)
		return (1);
	return (0);
}

static int	ft_trimend(const char *set, const char *ori)
{
	unsigned long int		i;

	i = ft_strlen(ori);
	while (ft_isset(ori[--i], set) == 1)
		;
	return (i);
}

static int	ft_trimstart(const char *set, const char *ori)
{
	unsigned long int		i;

	i = -1;
	while (ft_isset(ori[++i], set) == 1)
		;
	return (i);
}

char	*ft_strtrim(char const *str, char const *set)
{
	int		end;
	int		start;
	char	*p;
	int		i;

	if (!str)
		return ((char *) 0);
	if (ft_strlen(str) == 1)
		return ((char *)str);
	end = ft_trimend(set, str);
	start = ft_trimstart(set, str);
	if (end <= start)
		return (ft_strdup(""));
	p = malloc(sizeof(char) * ((end - start + 2)));
	if (!p)
		return (NULL);
	i = -1;
	while (++i < end - start + 1)
		p[i] = str[i + start];
	p[i] = '\0';
	free((void *)str);
	return (p);
}
