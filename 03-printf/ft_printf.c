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
#include "libft/libft.h"

static void	specs_init(char specs[9],
			int (*specificatori[8])(va_list *, t_modificatori))
{
	specs[0] = 'c';
	specs[1] = 's';
	specs[2] = 'd';
	specs[3] = 'i';
	specs[4] = 'p';
	specs[5] = 'u';
	specs[6] = 'x';
	specs[7] = 'X';
	specs[8] = 0;
	specificatori[0] = &spec_c;
	specificatori[1] = &spec_s;
	specificatori[2] = &spec_d;
	specificatori[3] = &spec_d;
	specificatori[4] = &spec_p;
	specificatori[5] = &spec_u;
	specificatori[6] = &spec_x;
	specificatori[7] = &spec_x;
	specificatori[8] = 0;

}

static	int	aggiungi_specif(const char *str, int *cont, va_list args)
{
	char			specs[9];
	int				(*specificatori[9]) (va_list *, t_modificatori);
	t_modificatori	modificatori;
	int				contSpecs;

	contSpecs = 0;
	specs_init(specs, specificatori);
	controlla_modif(args, str, cont, &modificatori);
	if (str[*cont] == '%')
	{
		(*cont)++;
		return (spec_r(modificatori));
	}
	while(specificatori[contSpecs])
	{
		if (str[*cont] == specs[contSpecs])
		{
			(*cont)++;
			if (contSpecs == 7)
				modificatori.maiuscoli_x = true;
				return (specificatori[contSpecs] (args, modificatori));
		}
		contSpecs++;
	}
	return (-1);
}

static int	ufficio_stampa(const char *str, va_list *arg, int n)
{
	int cont;
	int ret;

	cont = 0;
	while(str[cont])
	{
		if(str[cont] == '%')
		{
			cont++;
			if((ret = aggiungi_specif(str, &cont, arg)) < 0)
				return (-1);
			n = n + ret;
		}
		else
		{
			ft_putchar_fd(str[cont], FD);
			cont++;
			n++;
		}
	}
	return (n);
}

int			ft_printf(const char *str, ...)
{
	va_list	arg;
	int		n;

	va_start(arg, str);
	n = ufficio_stampa(str, &arg, 0);
	va_end(arg);
	return (n);
}
