/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    game_basic_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:48:23 by dmangola          #+#    #+#             */
/*   Updated: 2021/03/30 12:48:25 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_hit(int keycode, t_all *all)
{
	I_KEYBOARD[keycode] = 1;
	return (0);
}

int	key_release(int keycode, t_all *all)
{
	I_KEYBOARD[keycode] = 0;
	return (0);
}
