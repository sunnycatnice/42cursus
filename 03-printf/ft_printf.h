/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:43:11 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/28 15:43:13 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FD 1

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include "libft/libft.h"

# define BASE_8		"01234567"
# define BASE_10	"0123456789"
# define BASE_16	"0123456789abcdef"
# define BASE_16X	"0123456789ABCDEF"

typedef enum	e_bandiere
{
	zero = 0,
	meno = 1
}				t_bandiere;

typedef struct	s_modificatori
{
	bool	bandiere[2];
	int		width;
	bool	width_stato;
	int		precisione;
	bool	maiuscoli_x;
}				t_modificatori;

 typedef struct	s_par
{
	char	sflag;
	char	zflag;
	char	prec;
	int		width;
	int		prec_len;
	int		printed;
	char	error;
	va_list	arg;
}				t_par;


#endif