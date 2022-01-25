/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_doublestr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:13:08 by dmangola          #+#    #+#             */
/*   Updated: 2022/01/18 21:55:07 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dup_doublestr(char **str)
{
	char	**ret;
	int		len;

	len = ft_len_doublestr(str);
	ret = (char **)ft_calloc(sizeof(char *), len + 1);
	if (!ret)
		return (0);
	while (len--)
	{
		ret[len] = ft_strdup(str[len]);
		if (!ret[len])
			return (0);
	}
	return (ret);
}
