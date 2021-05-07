/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:13:43 by dmangola          #+#    #+#             */
/*   Updated: 2021/05/07 13:14:35 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "checker.h"

typedef struct		s_args
{
	int	*curr;
	int len;
	int	min;
	int	max;
}					t_args;

typedef struct		s_info
{
	int				len;
	int				max;
	int				min;
	int				pos_max;
	int				pos_min;
}					t_info;

typedef struct		s_a
{
	t_args		args;
	t_info		info_a;
	t_info		info_b;
}					t_a;

#endif
