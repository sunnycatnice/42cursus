/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:11:21 by ecarciof          #+#    #+#             */
/*   Updated: 2021/11/24 19:13:45 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static unsigned long int	ft_wc(const char *str)
{
	unsigned long int		i;
	unsigned long int		wordc;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	if (str[i] == '\0')
		return (0);
	wordc = 1;
	while (str[i])
	{
		while (str[i] && (str[i] != 32 && !(str[i] >= 9 && str[i] <= 13)))
			i++;
		while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
			i++;
		if (str[i])
			wordc++;
	}
	return (wordc);
}

static unsigned long int	ft_wl(const char *str)
{
	unsigned long int		res;

	res = -1;
	while (str[res] && (str[res] != 32 && !(str[res] >= 9 && str[res] <= 13)))
		;
	return (res);
}

static void	init(unsigned long int *a)
{
	*a = 0;
	a++;
	*a = -1;
}

char	**ft_split(char const *s)
{
	char				**mat;
	unsigned long int	v[3];

	if (!s)
		return (NULL);
	init(&v[0]);
	mat = (char **)malloc(sizeof(char *) * (ft_wc((char *)s) + 1));
	if (!mat)
		return (NULL);
	while (s[v[0]])
	{
		v[2] = -1;
		while (s[v[0]] == 32 || (s[v[0]] >= 9 && s[v[0]] <= 13))
			v[0]++;
		if (s[v[0]] == '\0')
			break ;
		mat[++v[1]] = (char *)malloc(sizeof(char) * (ft_wl(&s[v[0]]) + 1));
		if (!mat)
			return (NULL);
		while (s[v[0]] && (s[v[0]] != 32 && !(s[v[0]] >= 9 && s[v[0]] <= 13)))
			mat[v[1]][++v[2]] = s[v[0]++];
		mat[v[1]][++v[2]] = '\0';
	}
	mat[++v[1]] = NULL;
	return (mat);
}
