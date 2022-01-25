/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_doublestr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 00:43:56 by dmangola          #+#    #+#             */
/*   Updated: 2022/01/18 22:05:18 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_remove_doublestr(char **str, int idx)
{
	char	**ret;
	int		len;
	int		i;
	int		j;

	len = ft_len_doublestr(str);
	ret = (char **)ft_calloc(sizeof(char *), len);
	if (!ret)
		return (0);
	i = 0;
	j = 0;
	while (i < len)
	{
		ret[j++] = ft_strdup(str[i]);
		if (i != idx && !(ret[j]))
			return (0);
		i++;
	}
	ft_free_doublestr(&str);
	return (ret);
}
