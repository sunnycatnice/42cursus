/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:14:50 by dmangola          #+#    #+#             */
/*   Updated: 2021/02/13 14:21:16 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_check_spaces(const char *str, int *index, t_modifiers *modifiers)
{
	if (str[*index] == ' ')
	{
		ft_putchar_fd(' ', FD);
		while (str[*index] == ' ')
			(*index)++;
		return (modifiers->len_modified++);
	}
	return (0);
}
