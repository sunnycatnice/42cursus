/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:56:03 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(void)
{
	if (g_sh.checkif.header_vic)
	{
		printf("\n\n\n\n******************"
			"************************");
		printf("\n\n\n\t****MINISHELL****");
		printf("\n\n\t-USE AT YOUR OWN RISK-");
		printf("\n\n\n\n*******************"
			"***********************\n\n");
	}
	g_sh.firstoldpwd = 1;
	getcwd(g_sh.pwd, sizeof(g_sh.pwd));
}

int	is_useless(char c)
{
	if ((c == 92) || (c == 46) || (c == 59))
		return (1);
	else
		return (0);
}

char	*get_name(char *longstring, char *name)
{
	int	i;

	i = 0;
	while (longstring[i] != '=')
		i++;
	name = ft_substr(longstring, 0, i);
	return (name);
}
