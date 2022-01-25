/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:31:45 by bde-luca          #+#    #+#             */
/*   Updated: 2021/11/08 19:44:58 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		firstlen;
	int		secondlen;

	if (!s1 || !s2)
		return (0);
	firstlen = ft_strlen(s1);
	secondlen = ft_strlen(s2);
	s = (char *)ft_calloc(firstlen + secondlen + 1, sizeof(char));
	if (!s)
		return (0);
	ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	ft_strlcpy((char *)(s + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
	return (s);
}
