/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vceccaro <vceccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 00:53:21 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/22 21:23:39 by vceccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init(void)
{
	g_sh.cmds.idx = 0;
	g_sh.checkif.append_file = 0;
	g_sh.checkif.bool_pipes = 0;
	g_sh.checkif.input_file = 0;
	g_sh.checkif.output_file = 0;
	g_sh.checkif.delimiter_file = 0;
	g_sh.files.fd_file1 = -1;
	g_sh.files.fd_file2 = -1;
	g_sh.standard_in = dup(0);
	g_sh.standard_out = dup(1);
	g_sh.pipe.pipe_nbr = 0;
}

char	*ft_checkif_path(char *word)
{
	if (!(ft_strncmp(word, "/usr/local/bin/", 15)))
		return (ft_substr(word, 15, (ft_strlen(word) - 15)));
	else if (!(ft_strncmp(word, "/usr/bin/", 9)))
		return (ft_substr(word, 9, (ft_strlen(word) - 9)));
	else if (!(ft_strncmp(word, "/bin/", 5)))
		return (ft_substr(word, 5, (ft_strlen(word) - 5)));
	else if (!(ft_strncmp(word, "/usr/sbin/", 10)))
		return (ft_substr(word, 10, (ft_strlen(word) - 10)));
	else if (!(ft_strncmp(word, "/sbin/", 6)))
		return (ft_substr(word, 6, (ft_strlen(word) - 6)));
	else if (!(ft_strncmp(word, "/usr/local/munki/", 17)))
		return (ft_substr(word, 17, (ft_strlen(word) - 17)));
	return (word);
}
