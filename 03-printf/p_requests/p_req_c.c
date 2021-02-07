/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_req_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:56:32 by dmangola          #+#    #+#             */
/*   Updated: 2021/02/04 17:56:40 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	p_req_c(va_list *args, t_modifiers modifiers)
{
	char	c;
	int		cont_width;
	char	fill;

	c = va_arg(*args, int);
	cont_width = 1;
	fill = modifiers.flags[zero] ? '0' : ' ';
	if (modifiers.flags[minus])
		ft_putchar_fd(c, FD);
	while (modifiers.width - 1 > 0)
	{
		ft_putchar_fd(fill, FD);
		modifiers.width--;
		cont_width++;
	}
	if (!modifiers.flags[minus] || modifiers.flags[zero])
		ft_putchar_fd(c, FD);
	return (cont_width);
}
