/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 00:41:24 by dmangola          #+#    #+#             */
/*   Updated: 2022/01/18 22:08:52 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_startswith(const char *str, const char *sub)
{
	int	i;

	i = 0;
	while (sub[i] != '\0' && str[i] == sub[i])
		i++;
	return (sub[i] == '\0');
}
