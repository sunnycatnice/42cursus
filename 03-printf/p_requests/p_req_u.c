/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_req_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:59:10 by dmangola          #+#    #+#             */
/*   Updated: 2021/02/12 11:59:36 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_write_width(long *uns, int len, t_modifiers modifiers)
{
	int		n;
	char	fill;

	n = 0;
	fill = modifiers.flags[zero] ? '0' : ' ';
	if (modifiers.flags[zero] && (*uns) < 0)
	{
		ft_putchar_fd('-', FD);
		(*uns) *= -1;
	}
	while (modifiers.width - len > 0)
	{
		ft_putchar_fd(fill, FD);
		modifiers.width--;
		n++;
	}
	return (n);
}

static int	ft_write_prec(long *uns, int len, t_modifiers modifiers)
{
	int		n;
	
	n = 0;
	if(!(*uns) && !modifiers.precision)
		return (n);
	if ((*uns) < 0)
	{
		ft_putchar_fd('-', FD);
		(*uns) *= -1;
	}
	while (modifiers.precision - len > 0)
	{
		ft_putchar_fd('0', FD);
		modifiers.precision--;
		n++;
	}
	return (n);
}

static int	ft_print_u(long uns, int n, t_modifiers modifiers)
{
	int len;

	len = n;
	if(uns < 0)
		modifiers.precision++;
	if (modifiers.flags[minus])
	{
		n += ft_write_prec(&uns, len, modifiers);
		if (!(!uns && !modifiers.precision))
			ft_putnbr_fd(uns, FD);
	}
	n += ft_write_width(&uns, modifiers.precision > len ?
			modifiers.precision : len, modifiers);
	if (!modifiers.flags[minus] || modifiers.flags[zero])
	{
		n += ft_write_prec(&uns, len, modifiers);
		if(!(!uns && !modifiers.precision))
			ft_putnbr_fd(uns, FD);
	}
	return (n);
}

int			p_req_u(va_list *args, t_modifiers modifiers)
{
	unsigned int	uns;
	int				n;

	uns = va_arg(*args, unsigned int);
	if(!modifiers.precision && !modifiers.width && !uns)
		return (0);
	n = ft_ulnumlen_base(uns, 10);
	if (!uns && !modifiers.precision)
		n = 0;
	n = ft_print_u(uns, n, modifiers);
	return (n);
}
