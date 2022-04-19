/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vceccaro <vceccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:43:03 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/22 20:28:00 by vceccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unsetter(t_node *unset, t_node *bef, t_node *aft)
{
	aft = unset->next;
	unset->next = NULL;
	if (bef)
		bef->next = aft;
	else
		*g_sh.exp = aft;
	if (unset->name)
		free(unset->name);
	if (unset->string)
		free(unset->string);
	free(unset);
}
