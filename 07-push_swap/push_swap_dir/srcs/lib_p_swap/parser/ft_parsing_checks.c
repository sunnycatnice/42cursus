/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:47:39 by dmangola          #+#    #+#             */
/*   Updated: 2021/06/04 16:47:43 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	int	i;

	i = 0;
	while (V_DIGITS[i])
	{
		if (c == V_DIGITS[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_isvalidchar(char c)
{
	int	i;

	i = 0;
	while (V_CHARSET[i])
	{
		if (c == V_CHARSET[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_issymbol(char c)
{
	int	i;

	i = 0;
	while (V_SYMBOLS[i])
	{
		if (c == V_SYMBOLS[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_validarg(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (ft_isvalidchar(str[j]))
		{
			if (str[j] == '+' || str[j] == '-')
			{
				if (!(ft_isdigit(str[j + 1])))
					return (0);
			}
			if (ft_isdigit(str[j]))
			{
				if (!(str[j + 1] == ' ' || ft_isdigit(str[j + 1]) || \
				(!str[j + 1])))
					return (0);
			}
		}
		else
			return (0);
		j++;
	}
	return (1);
}
