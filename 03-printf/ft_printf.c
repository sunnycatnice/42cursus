/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:40:15 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/28 15:41:59 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_req(char type[9],
			int (*request[8])(va_list *, t_modifiers))
{
	type[0] = 'c';
	type[1] = 's';
	type[2] = 'd';
	type[3] = 'i';
	type[4] = 'p';
	type[5] = 'u';
	type[6] = 'x';
	type[7] = 'X';
	type[8] = 0;
	request[0] = &p_req_c;
	request[1] = &p_req_s;
	request[2] = &p_req_d;
	request[3] = &p_req_d;
	request[4] = &p_req_p;
	request[5] = &p_req_u;
	request[6] = &p_req_x;
	request[7] = &p_req_x;
	request[8] = 0;
}

static	int	ft_checking(const char *str, int *index,
			t_modifiers *modifiers)
{
	
	if (str[*index] == '%')
	{
		(*index)++;
		return (p_req_percent(*modifiers));
	}
	return (ft_check_spaces(str, index, modifiers) > 0 ? 1 : 0);
}

static	int	ft_print_types(const char *str, int *index, va_list *args)
{
	char			type[9];
	int				(*request[9])(va_list *, t_modifiers);
	t_modifiers		modifiers;
	int				index_req;

	index_req = 0;
	ft_init_req(type, request);
	ft_check_modifiers(args, str, index, &modifiers);
	while (request[index_req])
		{
			ft_checking(str, index, &modifiers);
			if (str[*index] == type[index_req])
			{
				(*index)++;
				if (index_req == 7)
					modifiers.upper_x = true;
				return (request[index_req](args, modifiers));
			}
			index_req++;
		}
	return (-1);
}

static int	ft_press_office(const char *str, va_list *args, int len)
{
	int index;
	int len_modifiers;

	index = 0;
	while (str[index])
	{
		if (str[index] == '%')
		{
			index++;
			if ((len_modifiers = ft_print_types(str, &index, args)) < 0)
				return (-1);
			len += len_modifiers;
		}
		else
		{
			ft_putchar_fd(str[index], FD);
			index++;
			len++;
		}
	}
	return (len);
}

int			ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = ft_press_office(str, &args, 0);
	va_end(args);
	return (len);
}
