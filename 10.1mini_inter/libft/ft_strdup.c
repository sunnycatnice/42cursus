/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:01:49 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/19 16:59:23 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	idx;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ptr == NULL)
		return (NULL);
	idx = -1;
	while (s[++idx])
		ptr[idx] = s[idx];
	ptr[idx] = '\0';
	return (ptr);
}
