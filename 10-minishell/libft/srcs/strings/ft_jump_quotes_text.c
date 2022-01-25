/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump_quotes_text.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:02:04 by bde-luca          #+#    #+#             */
/*   Updated: 2021/11/08 19:44:58 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_jump_quotes_text(char *line, int *i, int dquote)
{
	if (dquote && line[*i] == '"')
	{
		++(*i);
		return ;
	}
	++(*i);
	while (line[*i])
	{
		if (!dquote && line[*i] == '\'')
			break ;
		if (dquote && line[*i] == '"' && !ft_isescaped(line, *i - 1))
			break ;
		++(*i);
	}
	++(*i);
}
