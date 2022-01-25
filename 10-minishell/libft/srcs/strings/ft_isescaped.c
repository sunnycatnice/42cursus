/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isescaped.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:26:52 by bde-luca          #+#    #+#             */
/*   Updated: 2021/11/08 19:44:58 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isescaped(char *line, int i)
{
	int	bkslhs;

	bkslhs = 0;
	if (i < 0)
		return (0);
	while (i && line[i] == '\\')
	{
		++bkslhs;
		--i;
	}
	if (bkslhs % 2 == 0)
		return (0);
	return (1);
}
