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

#include "ft_printf.h"

void ft_controlla_modif(va_list *args, const char *str, int *cont,
		t_modificatori *modificatori)
{
	modificatori->bandiere[0] = false;
	modificatori->bandiere[1] = false;
	modificatori->width = -1;
	modificatori->width_stato = false;
	modificatori->precisione = -1;
	modificatori->maiuscoli_x = false;
	controlla_bandiere(str, cont, modificatori);
	controlla_width(args, str, cont, modificatori);
	controlla_precisione(args, str, cont, modificatori);
	if (modificatori->bandiere[meno] || modificatori->precisione > -1)
		modificatori->bandiere[zero] = false;
}