/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_doublestr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 00:43:45 by dmangola          #+#    #+#             */
/*   Updated: 2022/01/18 22:16:56 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc_doublestr(char ***strs_ref, char *item)
{
	char	**ret;
	char	**strs;
	int		len;

	strs = *strs_ref;
	if (!item)
		return (strs);
	len = ft_len_doublestr(strs) + 2;
	ret = (char **)ft_calloc(sizeof(char *), len--);
	if (!ret)
		return (0);
	ret[--len] = ft_strdup(item);
	while (len--)
	{
		ret[len] = ft_strdup(strs[len]);
		if (!ret)
			return (0);
	}
	*strs_ref = ret;
	ft_free_doublestr(&strs);
	return (ret);
}
