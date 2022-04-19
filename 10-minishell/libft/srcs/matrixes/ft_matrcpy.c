/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:07:44 by bde-luca          #+#    #+#             */
/*   Updated: 2022/04/19 14:58:54 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"
#include <stdio.h>

int	ft_mtx_len_wid(char **m, short info)
{
	int		i;
	int		wid;

	i = 0;
	wid = 0;
	while (m[i])
	{
		if (ft_strlen(m[i]) > wid)
			wid = ft_strlen(m[i]);
		i++;
	}
	if (info == 0)
		return (i);
	else
		return (wid);
}

char	**ft_mtxcpy(char **m)
{
	char	**dst;

	dst = malloc(sizeof(**m));
	if (!dst)
	{
		ft_putstr_fd("Malloc error in copying envp\n", 1);
		return ((char **)1);
	}
	dst = m;
	return (dst);
}
