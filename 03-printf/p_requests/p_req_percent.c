/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_req_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 11:57:44 by dmangola          #+#    #+#             */
/*   Updated: 2021/02/06 11:57:59 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	p_req_percent(t_modifiers modifiers)
{
	int		n;
	char	fill;

	n = 1;
	fill = modifiers.flags[zero] ? '0' : ' ';
	if (modifiers.flags[minus])
		ft_putchar_fd('%', FD);
	while (modifiers.width - 1 > 0)
	{
		ft_putchar_fd(fill, FD);
		modifiers.width--;
		n++;
	}
	if (!modifiers.flags[minus] || modifiers.flags[zero])
		ft_putchar_fd('%', FD);
	return (n);
}
