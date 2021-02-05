/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 13:46:47 by dmangola          #+#    #+#             */
/*   Updated: 2021/02/04 13:46:48 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_simple_atoi(const char *str, int *index)
{
	int ret;

	ret = 0;
	while (ft_isdigit(str[*index]))
	{
		ret = ret * 10 + (str[*index] - '0');
		(*index)++;
	}
	return (ret);
}