/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:20:40 by sungslee          #+#    #+#             */
/*   Updated: 2020/08/05 18:23:27 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lltoa(long long n)
{
	long long	div;
	int			len;
	char		*res;

	div = n;
	len = (n <= 0) ? 1 : 0;
	while (div != 0)
	{
		div /= 10;
		len++;
	}
	if (!(res = malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	if (n <= 0)
		res[0] = (n == 0) ? '0' : '-';
	while (n != 0)
	{
		len--;
		res[len] = (n > 0) ? (n % 10) + '0' : -(n % 10) + '0';
		n /= 10;
	}
	return (res);
}
