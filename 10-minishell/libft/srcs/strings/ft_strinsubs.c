/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsubs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:07:59 by bde-luca          #+#    #+#             */
/*   Updated: 2021/11/08 19:44:58 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinsubs(const char *body, const char *to_insert,
	int subslen, int in_pos)
{
	char	*new;
	int		insertlen;
	int		escapes;

	if (!body || !to_insert)
		return (0);
	escapes = 0;
	insertlen = ft_strlen(to_insert);
	new = (char *)ft_calloc(ft_strlen(body) - subslen + \
		insertlen + 1, sizeof(char));
	if (!new)
		return (0);
	ft_strlcpy(new, body, in_pos + 1);
	ft_strlcpy((char *)(new + in_pos), to_insert, ft_strlen(to_insert) + 1);
	while (body[in_pos + subslen + escapes] == '\\')
		++escapes;
	if (escapes == 1)
		subslen++;
	else
		subslen += escapes / 2;
	ft_strlcpy((char *)(new + in_pos + \
		ft_strlen(to_insert)), (char *)(body + in_pos + subslen), \
		ft_strlen((char *)(body + in_pos + subslen)) + 1);
	return (new);
}
