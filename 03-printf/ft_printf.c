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

static void	ft_init_req(char print_req[9],
			int (*requests[8])(va_list *, t_modifiers))
{
	print_req[0] = 'c';
	print_req[1] = 's';
	print_req[2] = 'd';
	print_req[3] = 'i';
	print_req[4] = 'p';
	print_req[5] = 'u';
	print_req[6] = 'x';
	print_req[7] = 'X';
	print_req[8] = 0;
	requests[0] = &p_req_c;
	requests[1] = &p_req_s;
	// requests[2] = &p_req_d;
	// requests[3] = &p_req_d;
	// requests[4] = &p_req_p;
	// requests[5] = &p_req_u;
	// requests[6] = &p_req_x;
	// requests[7] = &p_req_x;
	// requests[8] = 0;

}

static	int	ft_add_spec(const char *str, int *index, va_list *args)
{
	char			print_req[9];
	int				(*requests[9]) (va_list *, t_modifiers);
	t_modifiers		modifiers;
	int				index_req;

	index_req = 0;
	ft_init_req(print_req, requests);
	ft_check_modifiers(args, str, index, &modifiers);
	if (str[*index] == '%')
	{
		(*index)++;
		return (p_req_percent(modifiers));
	}
	while(requests[index_req])
	{
		if (str[*index] == print_req[index_req])
		{
			(*index)++;
			if (index_req == 7)
				modifiers.upper_x = true;
			return (requests[index_req] (args, modifiers));
		}
		index_req++;
	}
	return (-1);
}

static int	ft_press_office(const char *str, va_list *args, int len)
{
	int index;
	int lung_specs;

	index = 0;
	while(str[index])
	{
		if(str[index] == '%')
		{
			index++;
			if((lung_specs = ft_add_spec(str, &index, args)) < 0)
				return (-1);
			len+= lung_specs;
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