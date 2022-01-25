/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:51:17 by bde-luca          #+#    #+#             */
/*   Updated: 2021/11/08 19:44:58 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

static void	ft_write_base(unsigned long long nbr, char *base,
		unsigned int baselen, int fd)
{
	if (nbr >= baselen)
	{
		ft_write_base(nbr / baselen, base, baselen, fd);
		ft_write_base(nbr % baselen, base, baselen, fd);
	}
	else
		write(1, &base[nbr], fd);
}

static bool	ft_is_not_printable_or_sign(char *base, int index)
{
	if (base[index] == ' ' || base[index] == '\f' || base[index] == '\r'
		|| base[index] == '\n' || base[index] == '\t'
		|| base[index] == '\v' || base[index] == '+' || base[index] == '-')
		return (true);
	return (false);
}

static int	ft_is_base_valid(char *base, int index)
{
	int		duplicate;

	while (base[index] != '\0')
	{
		if (ft_is_not_printable_or_sign(base, index))
			return (0);
		duplicate = index + 1;
		while (base[duplicate] != '\0')
		{
			if (base[index] == base[duplicate])
				return (0);
			duplicate++;
		}
		index++;
	}
	return (index);
}

void	ft_putunbr_base_fd(unsigned long long nbr, char *base, int fd)
{
	if (ft_is_base_valid(base, 0) > 1)
		ft_write_base(nbr, base, ft_is_base_valid(base, 0), fd);
}
