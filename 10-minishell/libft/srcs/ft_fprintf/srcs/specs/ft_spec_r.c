/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:55:45 by bde-luca          #+#    #+#             */
/*   Updated: 2021/11/08 19:44:58 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_spec_r(t_modifiers modifiers)
{
	int		n;
	char	fill;

	n = 1;
	if (modifiers.flags[zero])
		fill = '0';
	else
		fill = ' ';
	if (modifiers.flags[minus])
		ft_putchar_fd('%', modifiers.fd);
	while (modifiers.width - 1 > 0)
	{
		ft_putchar_fd(fill, modifiers.fd);
		modifiers.width--;
		n++;
	}
	if (!modifiers.flags[minus] || modifiers.flags[zero])
		ft_putchar_fd('%', modifiers.fd);
	return (n);
}
