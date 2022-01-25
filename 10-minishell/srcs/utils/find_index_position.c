/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:25:01 by bde-luca          #+#    #+#             */
/*   Updated: 2021/12/15 12:39:16 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_index_position(char **src, char *to_find)
{
	int	i;

	i = 0;
	while (src[i] && ft_strncmp(src[i], to_find, ft_strlen(to_find)))
		i++;
	return (i);
}
