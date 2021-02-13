/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controlla_modif.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:12:55 by dmangola          #+#    #+#             */
/*   Updated: 2021/02/02 18:12:56 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		check_precision(va_list *args, const char *str, int *index,
		t_modifiers *modifiers)
{
	if (str[*index] != '.')
		return ;
	(*index)++;
	if (str[*index] == '*')
	{
		modifiers->precision = va_arg(*args, int);
		(*index)++;
	}
	else if (ft_isdigit(str[*index]))
		modifiers->precision = ft_simple_atoi(str, index);
	else
		modifiers->precision = 0;
	while (1)
	{
		if (ft_isdigit(str[*index]))
			(*index)++;
		else if (str[*index] == '*')
		{
			va_arg(*args, int);
			(*index)++;
		}
		else
			return ;
	}
}

static void		check_width(va_list *args, const char *str, int *index,
		t_modifiers *modifiers)
{
	while (1)
	{
		if (ft_isdigit(str[*index]))
		{
			modifiers->width_state = true;
			modifiers->width = ft_simple_atoi(str, index);
		}
		else if (str[*index] == '*')
		{
			modifiers->width_state = true;
			modifiers->width = va_arg(*args, int);
			(*index)++;
		}
		else
		{
			if (modifiers->width < 0 && modifiers->width_state)
			{
				modifiers->flags[minus] = true;
				modifiers->width *= -1;
			}
			return ;
		}
	}
}

static void	check_flags(const char *str, int *index, t_modifiers *modifiers)
{
	char	flagset[3];
	int		j;

	flagset[0] = '0';
	flagset[1] = '-';
	flagset[2] = 0;
	j = 0;
	while (flagset[j])
	{
		if (str[*index] == flagset[j])
		{
			modifiers->flags[j] = true;
			(*index)++;
			j = -1;
		}
		j++;
	}
}

static void	init_modifiers(t_modifiers *modifiers)
{
	modifiers->flags[0] = false;
	modifiers->flags[1] = false;
	modifiers->width = -1;
	modifiers->width_state = false;
	modifiers->precision = -1;
	modifiers->upper_x = false;
}

void		ft_check_modifiers(va_list *args, const char *str, int *index,
		t_modifiers *modifiers)
{
	init_modifiers(modifiers);
	check_flags(str, index, modifiers);
	check_width(args, str, index, modifiers);
	check_precision(args, str, index, modifiers);
	if (modifiers->flags[minus] || modifiers->precision > -1)
		modifiers->flags[zero] = false;
}
