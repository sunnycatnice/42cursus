/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control_correct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:58:13 by dmangola          #+#    #+#             */
/*   Updated: 2021/04/12 19:58:40 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_in_charset_adjust(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S' || c == '0')
		return (0);
	else if (c == '1' || ft_isspace(c) || !c)
		return (1);
	else if (c == '2')
		return (2);
	return (3);
}

void		adjust_map(t_a *a)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (i < a->in.map_height)
	{
		j = 0;
		while (j < a->in.map_width)
		{
			ret = is_in_charset_adjust(a->map[i][j]);
			if (!ret)
				a->map[i][j] = 0;
			else if (ret == 1)
				a->map[i][j] = 1;
			else if (ret == 2)
				a->map[i][j] = 2;
			else
				ft_print_error(a, 18);
			j++;
		}
		i++;
	}
}

static void	is_in_charset_control(t_a *a, char c, int i, int j)
{
	if (c == '0' || c == '1' || c == '2' || ft_isspace(c) || !c)
		return ;
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (a->in.player)
			ft_print_error(a, 17);
		a->in.player = a->map[i][j];
		a->player.posx = j;
		a->player.posy = i;
		return ;
	}
	ft_print_error(a, 18);
}

void		control_constraits(t_a *a, int i, int j)
{
	if (i - 1 < 0 || j - 1 < 0 ||
	i + 1 == a->in.map_height || j + 1 == a->in.map_width)
		ft_print_error(a, 16);
	if (!a->map[i + 1][j + 1] || a->map[i + 1][j + 1] == ' ')
		ft_print_error(a, 16);
	if (!a->map[i - 1][j - 1] || a->map[i - 1][j - 1] == ' ')
		ft_print_error(a, 16);
	if (!a->map[i + 1][j - 1] || a->map[i + 1][j - 1] == ' ')
		ft_print_error(a, 16);
	if (!a->map[i - 1][j + 1] || a->map[i - 1][j + 1] == ' ')
		ft_print_error(a, 16);
}

void		control_map(t_a *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->in.map_height)
	{
		j = 0;
		while (j < a->in.map_width)
		{
			is_in_charset_control(a, a->map[i][j], i, j);
			if (!is_in_charset_adjust(a->map[i][j]) ||
			is_in_charset_adjust(a->map[i][j]) == 2)
				control_constraits(a, i, j);
			j++;
		}
		i++;
	}
	if (!a->in.player)
		ft_print_error(a, 15);
}

