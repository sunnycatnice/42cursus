/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_req_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:15:31 by dmangola          #+#    #+#             */
/*   Updated: 2021/02/12 15:15:35 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_write_width(int len, t_modifiers modifiers)
{
	int		n;
	char	fill;

	n = 0;
	fill = modifiers.flags[zero] ? '0' : ' ';
	while (modifiers.width - len > 0)
	{
		ft_putchar_fd(fill, FD);
		modifiers.width--;
		n++;
	}
	return (n);
}

static int	ft_write_prec(size_t *exa, int len, t_modifiers modifiers)
{
	int n;

	n = 0;
	if (!(*exa) && !modifiers.precision)
		return (n);
	while (modifiers.precision - len > 0)
	{
		ft_putchar_fd('0', FD);
		modifiers.precision--;
		n++;
	}
	return (n);
}

static int	ft_print_x(size_t exa, int n, t_modifiers modifiers)
{
	int len;

	len = n;
	if (exa < 0)
		modifiers.precision++;
	if (modifiers.flags[minus])
	{
		n += ft_write_prec(&exa, len, modifiers);
		if (!(!exa && !modifiers.precision))
			ft_putnbr_base_fd(exa, modifiers.upper_x ? BASE_16X : BASE_16, FD);
	}
	n += ft_write_width(modifiers.precision > len ?
			modifiers.precision : len, modifiers);
	if (!modifiers.flags[minus] || modifiers.flags[zero])
	{
		n += ft_write_prec(&exa, len, modifiers);
		if (!(!exa && !modifiers.precision))
			ft_putnbr_base_fd(exa, modifiers.upper_x ? BASE_16X : BASE_16, FD);
	}
	return (n);
}

int			p_req_x(va_list *args, t_modifiers modifiers)
{
	unsigned int	exa;
	int				n;

	exa = va_arg(*args, unsigned int);
	if (!modifiers.precision && !modifiers.width && !exa)
		return (0);
	n = ft_unumlen_base(exa, 16);
	if (!exa && !modifiers.precision)
		n = 0;
	n = ft_print_x(exa, n, modifiers);
	return (n);
}
