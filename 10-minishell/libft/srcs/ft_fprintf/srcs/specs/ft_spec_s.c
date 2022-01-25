/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:27:53 by bde-luca          #+#    #+#             */
/*   Updated: 2021/11/08 19:44:58 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	ft_initialize_fill(t_modifiers modifiers, char *fill)
{
	if (modifiers.flags[zero])
		*fill = '0';
	else
		*fill = ' ';
}

int	ft_spec_s(va_list *args, t_modifiers modifiers)
{
	char	*s;
	int		len;
	int		n;
	char	fill;

	s = va_arg(*args, char *);
	if (!s)
		s = "";
	len = ft_strlen(s);
	ft_initialize_fill(modifiers, &fill);
	if (modifiers.precision > len)
		len = modifiers.precision;
	n = len;
	if (modifiers.flags[minus])
		ft_putstrlen_fd(s, len, modifiers.fd);
	while (modifiers.width - len > 0)
	{
		ft_putchar_fd(fill, modifiers.fd);
		modifiers.width--;
		n++;
	}
	if (!modifiers.flags[minus] || modifiers.flags[zero])
		ft_putstrlen_fd(s, len, modifiers.fd);
	return (n);
}
