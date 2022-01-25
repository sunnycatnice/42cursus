/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:10:49 by bde-luca          #+#    #+#             */
/*   Updated: 2021/11/08 19:44:58 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcharjoin(char *old, char c)
{
	char	*new;
	int		i;

	if (!old)
		new = (char *)ft_calloc(2, sizeof(char));
	else
		new = (char *)ft_calloc(ft_strlen(old) + 2, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (old && old[i])
	{
		new[i] = old[i];
		i++;
	}
	new[i] = c;
	ft_if_free((void **)&old);
	return (new);
}
