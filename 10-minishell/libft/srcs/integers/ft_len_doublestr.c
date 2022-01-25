/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_doublestr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:46:59 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/18 22:18:19 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_doublestr(char **str)
{
	int		idx;

	idx = 0;
	if (!str || !(*str))
		return (0);
	while (*str++)
		idx++;
	return (idx);
}
