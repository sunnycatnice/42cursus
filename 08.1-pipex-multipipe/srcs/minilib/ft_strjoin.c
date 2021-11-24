/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:11:18 by ecarciof          #+#    #+#             */
/*   Updated: 2021/11/24 19:13:45 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*p;
	size_t		i;
	size_t		j;
	size_t		act;

	if (!s1 || !s2)
		return ((char *) 0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	act = -1;
	p = (char *)malloc(sizeof(char) * (i + j + 2));
	if (!p)
		return ((char *) 0);
	while (++act < i)
		p[act] = s1[act];
	while (++act < i + j + 1)
		p[act - 1] = s2[act - i - 1];
	p[act - 1] = '\0';
	return (p);
}

char	*ft_strjoin3(char const *s1, char const *s2)
{
	char		*p;
	size_t		i;
	size_t		j;
	size_t		act;

	if (!s1 || !s2)
		return ((char *) 0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	act = -1;
	p = (char *)malloc(sizeof(char) * (i + j + 2));
	if (!p)
		return ((char *) 0);
	while (++act < i)
		p[act] = s1[act];
	while (++act < i + j + 1)
		p[act - 1] = s2[act - i - 1];
	p[act - 1] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (p);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char		*p;
	size_t		i;
	size_t		j;
	size_t		act;

	if (!s1 || !s2)
		return ((char *) 0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	act = -1;
	p = (char *)malloc(sizeof(char) * (i + j + 2));
	if (!p)
		return ((char *) 0);
	while (++act < i)
		p[act] = s1[act];
	while (++act < i + j + 1)
		p[act - 1] = s2[act - i - 1];
	p[act - 1] = '\0';
	free((char *)s2);
	return (p);
}

char	*ft_strjoin1(char const *s1, char const *s2)
{
	char		*p;
	size_t		i;
	size_t		j;
	size_t		act;

	if (!s1 || !s2)
		return ((char *) 0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	act = -1;
	p = (char *)malloc(sizeof(char) * (i + j + 2));
	if (!p)
		return ((char *) 0);
	while (++act < i)
		p[act] = s1[act];
	while (++act < i + j + 1)
		p[act - 1] = s2[act - i - 1];
	p[act - 1] = '\0';
	free((char *)s1);
	return (p);
}
