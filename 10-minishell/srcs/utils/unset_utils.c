/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:43:03 by bde-luca          #+#    #+#             */
/*   Updated: 2022/01/24 18:51:10 by dmangola         ###   ########.fr       */
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
