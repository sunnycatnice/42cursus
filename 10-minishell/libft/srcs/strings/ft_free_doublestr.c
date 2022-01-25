/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_doublestr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 00:42:49 by dmangola          #+#    #+#             */
/*   Updated: 2022/01/18 21:55:51 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_doublestr(char ***doublestr_addr)
{
	int		i;
	char	**doublestr;

	if (!doublestr_addr || !(*doublestr_addr))
		return (0);
	i = -1;
	doublestr = *doublestr_addr;
	while (doublestr[++i])
		ft_free_str(&doublestr[i]);
	ft_free(doublestr);
	*doublestr_addr = 0;
	return (1);
}
