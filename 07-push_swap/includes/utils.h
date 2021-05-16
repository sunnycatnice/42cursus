/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:38:27 by dmangola          #+#    #+#             */
/*   Updated: 2021/05/05 12:38:28 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "checker.h"
# include "push_swap.h"
# include "struct.h"
# include <stdio.h>

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
/*
** Graphic part
*/
void	ft_red_color(void);
void	ft_green_color(void);
void	ft_reset_color(void);
void	ft_print_start_ck(void);
void	ft_print_start_ps(void);

#endif