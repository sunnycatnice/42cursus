/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_req_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:56:46 by dmangola          #+#    #+#             */
/*   Updated: 2021/02/04 17:56:47 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			p_req_d(va_list *args, t_modifiers modifiers)
{
	int i;
	int num;

	i = (long)va_arg(*args, int);
	if (!modifiers->precision && !modifiers.width && !i)
		return (0);
	num = ft_numlen_base(i, 10);
	if(!i && !modifiers->precision)
		num = 0;
	num = ft_decimal_office(i, num, modifiers);
	return (num);
}