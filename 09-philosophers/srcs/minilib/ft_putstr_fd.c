/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:00:22 by dmangola          #+#    #+#             */
/*   Updated: 2021/09/02 17:00:23 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	ft_putstr_fd(char const *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}

void	ft_putstr_star_fd(char *s, int fd)
{
	char	*s_copy;

	s_copy = s;
	ft_printstars(s);
	while (*s)
		ft_putchar_fd(*s++, fd);
	ft_printstars(s_copy);
}
