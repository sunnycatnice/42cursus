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

# define FD	1

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>

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
	bool		space;
	int			width;
	bool		width_state;
	int			precision;
	bool		upper_x;
}				t_modifiers;

/*
** dir print requests
*/
int			p_req_c(va_list *args, t_modifiers modifiers);
int			p_req_s(va_list *args, t_modifiers modifiers);
int			p_req_d(va_list *args, t_modifiers modifiers);
int			p_req_p(va_list *args, t_modifiers modifiers);
int			p_req_u(va_list *args, t_modifiers modifiers);
int			p_req_x(va_list *args, t_modifiers modifiers);
int			p_req_percent(t_modifiers modifiers);
/*
** dir utils
*/
void		ft_check_modifiers(va_list *args, const char *str, int *index,
			t_modifiers *modifiers);
void		ft_check_spaces(const char *str, int *index, t_modifiers *modifiers);
void		ft_putstrlen_fd(char *str, int len, int fd);
int			ft_isdigit(int c);
int			ft_numlen_base(int num, int base);
int			ft_unumlen_base(unsigned int i, int base);
int			ft_ulnumlen_base(unsigned long i, int base);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(long n, int fd);
void		ft_putnbr_base_fd(size_t nbr, char *base, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_simple_atoi(const char *str, int *index);
int			ft_strlen(char *str);
/*
** ft_printf.c
*/
int			ft_printf(const char *str, ...);

#endif