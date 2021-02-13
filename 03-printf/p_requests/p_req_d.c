/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_req_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:59:21 by dmangola          #+#    #+#             */
/*   Updated: 2021/02/07 14:59:23 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_put_width(long *decimal, int len, t_modifiers modifiers)
{
	int 	num;
	char 	fill;

	num = 0;
	fill = modifiers.flags[zero] ? '0' : ' ';
	if (modifiers.flags[zero] && (*decimal) < 0)
	{
		ft_putchar_fd('-', FD);
		(*decimal) = (*decimal) * -1;
	}
	while (modifiers.width - len > 0)
	{
		ft_putchar_fd(fill, FD);
		modifiers.width--;
		num++;
	}
	return (num);
}

static int	ft_put_prec(long *decimal, int len, t_modifiers modifiers)
{
	int num;

	num = 0;
	if (!(*decimal) && !modifiers.precision)
		return (num);
	if((*decimal) < 0)
	{
		ft_putchar_fd('-', FD);
		(*decimal) *= -1;
	}
	while (modifiers.precision - len > 0)
	{
		ft_putchar_fd('0', FD);
		modifiers.precision--;
		num++;
	}
	return (num);
}

static int	ft_print_manager(long decimal, int num, t_modifiers modifiers)
{
	int len;

	len = num;
	if(decimal < 0)
		modifiers.precision++;
	if(modifiers.flags[minus])
	{
		num += ft_put_prec(&decimal, len, modifiers);
		if (!(!decimal && !modifiers.precision))
			ft_putnbr_fd(decimal, FD);
	}
	num += ft_put_width(&decimal, modifiers.precision > len ? 
		modifiers.precision : len , modifiers);
	if(!modifiers.flags[minus] || modifiers.flags[zero])
	{
		num += ft_put_prec(&decimal, len, modifiers);
		if(!(!decimal && !modifiers.precision))
			ft_putnbr_fd(decimal, FD);
	}
	return (num);
}

int			p_req_d(va_list *args, t_modifiers modifiers)
{
	long	decimal;
	int		num;

	decimal = (long)va_arg(*args, int);
	if (!modifiers.precision && !modifiers.width && !decimal)
		return (0);
	num = ft_numlen_base(decimal, 10);
	if (!decimal && !modifiers.precision)
		num = 0;
	num = ft_print_manager(decimal, num, modifiers);
	return (num);
}
