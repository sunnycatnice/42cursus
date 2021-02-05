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

# define BASE_8		"01234567"
# define BASE_10	"0123456789"
# define BASE_16	"0123456789abcdef"
# define BASE_16X	"0123456789ABCDEF"

typedef enum	e_flags
{
	zero = 0,
	minus = 1
}				t_flags;

typedef struct	s_modifiers
{
	bool		flags[2];
	int			width;
	bool		width_state;
	int			precision;
	bool		upper_x;
}				t_modifiers;

int			ft_simple_atoi(const char *str, int *index);
int			ft_isdigit(int c);
int			p_req_c(va_list *args, t_modifiers modifiers);
void		ft_putchar_fd(char c, int fd);
void		ft_check_modifiers(va_list *args, const char *str, int *index,
			t_modifiers *modifiers);

#endif