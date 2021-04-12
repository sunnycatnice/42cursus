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

void		adjust_map(t_all *all)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (i < I_MAP_HEIGHT)
	{
		j = 0;
		while (j < I_MAP_WIDTH)
		{
			ret = is_in_charset_adjust(CPP_MAP[i][j]);
			if (!ret)
				CPP_MAP[i][j] = 0;
			else if (ret == 1)
				CPP_MAP[i][j] = 1;
			else if (ret == 2)
				CPP_MAP[i][j] = 2;
			else
				ft_print_error(all, 18);
			j++;
		}
		i++;
	}
}

static void	is_in_charset_control(t_all *all, char c, int i, int j)
{
	if (c == '0' || c == '1' || c == '2' || ft_isspace(c) || !c)
		return ;
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (I_PLAYER)
			ft_print_error(all, 17);
		I_PLAYER = CPP_MAP[i][j];
		I_PLAYER_X = j;
		I_PLAYER_Y = i;
		return ;
	}
	ft_print_error(all, 18);
}

void		control_constraits(t_all *all, int i, int j)
{
	if (i - 1 < 0 || j - 1 < 0 ||
	i + 1 == I_MAP_HEIGHT || j + 1 == I_MAP_WIDTH)
		ft_print_error(all, 16);
	if (!CPP_MAP[i + 1][j + 1] || CPP_MAP[i + 1][j + 1] == ' ')
		ft_print_error(all, 16);
	if (!CPP_MAP[i - 1][j - 1] || CPP_MAP[i - 1][j - 1] == ' ')
		ft_print_error(all, 16);
	if (!CPP_MAP[i + 1][j - 1] || CPP_MAP[i + 1][j - 1] == ' ')
		ft_print_error(all, 16);
	if (!CPP_MAP[i - 1][j + 1] || CPP_MAP[i - 1][j + 1] == ' ')
		ft_print_error(all, 16);
}

void		control_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < I_MAP_HEIGHT)
	{
		j = 0;
		while (j < I_MAP_WIDTH)
		{
			is_in_charset_control(all, CPP_MAP[i][j], i, j);
			if (!is_in_charset_adjust(CPP_MAP[i][j]) ||
			is_in_charset_adjust(CPP_MAP[i][j]) == 2)
				control_constraits(all, i, j);
			j++;
		}
		i++;
	}
	if (!I_PLAYER)
		ft_print_error(all, 15);
}

