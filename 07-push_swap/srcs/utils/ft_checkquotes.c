/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkquotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:22:20 by dmangola          #+#    #+#             */
/*   Updated: 2021/05/16 16:22:21 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		ft_checkquotes(char *argument)
{
	int n;

	n = 0;
	while (argument[n])
	{
		if (argument[0] == '-')
        	n++;
		if (!ft_isdigit(argument[n]))
			return(1);
		n++;
	}
	return(0);
}
