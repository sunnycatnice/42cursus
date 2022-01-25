/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:28:41 by bde-luca          #+#    #+#             */
/*   Updated: 2021/11/28 19:29:13 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_unclosed_quotes(char *line)
{
	int	a;
	int	q;
	int	i;

	a = 0;
	q = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\"')
			q++;
		if (line[i] == '\'')
			a++;
		i++;
	}
	if ((q % 2 != 0) || (a % 2 != 0))
	{
		printf("Error: unclosed quotes/apex\n");
		return (1);
	}
	else
		return (0);
}
