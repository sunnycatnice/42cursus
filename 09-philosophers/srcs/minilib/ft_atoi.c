/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:00:04 by dmangola          #+#    #+#             */
/*   Updated: 2021/09/02 17:00:05 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

long int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long long	result;

	result = 0;
	i = 0;
	while (is_space(str[i]))
		i++;
	neg = is_neg(str[i]);
	if (neg == -1)
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		result = result * 10 + (str[i] - '0');
		i++;
		if (result > 2147483648)
			break ;
	}
	return (neg * (long int)result);
}
