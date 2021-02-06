/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_req_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:17:25 by dmangola          #+#    #+#             */
/*   Updated: 2021/02/06 16:17:29 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		p_req_s(va_list *args, t_modifiers modifiers)
{
	char	*string;
	int 	len;
	int		lenandwidth;
	int		fill;

	string = va_arg(*args, char *);
	if (!string)
		string = "(null)";
	len = ft_strlen(string);
	fill = modifiers.flags[zero] ? '0' : ' ';
	if (modifiers.precision > -1)
		len = modifiers.precision > len ? len : modifiers.precision;
	lenandwidth = len;
	if (modifiers.flags[minus])
		ft_putstrlen_fd(string, len, FD);
	while (modifiers.width - len > 0)
	{
		ft_putchar_fd(fill, FD);
		modifiers.width--;
		lenandwidth++;
	}
	if (!modifiers.flags[minus] || modifiers.flags[zero])
		ft_putstrlen_fd(string, len, FD);
	return (lenandwidth);
}
