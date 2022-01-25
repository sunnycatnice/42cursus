/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bnessi_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:02:55 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** This is Barbara Nessi's split
*/

static int	ft_count(char const *s, char c)
{
	unsigned int	i;
	int				cntr;

	i = 0;
	cntr = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cntr++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (cntr);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**do_the_tab(char const *str, char **tab, int i, char c)
{
	int	j;
	int	k;

	k = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		j = i;
		while (str[i] && str[i] != c)
			i++;
		if (i > j)
		{
			tab[k] = ft_strndup(str + j, i - j);
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_bnessi_split(char const *s, char c)
{
	int		i;
	char	**tab;

	i = 0;
	if (s == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_count(s, c)) + 1);
	if (!tab)
		return (NULL);
	return (do_the_tab(s, tab, i, c));
}
