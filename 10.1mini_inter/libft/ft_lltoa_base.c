/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:15:32 by sungslee          #+#    #+#             */
/*   Updated: 2020/08/08 20:33:34 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa_base(long long n, const char *base)
{
	long long		div;
	int				len;
	long long		base_len;
	char			*ret;

	div = (n < 0) ? -n : n;
	len = (n <= 0) ? 1 : 0;
	base_len = (long long)ft_strlen((char *)base);
	while (div != 0)
	{
		div = div / base_len;
		len++;
	}
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (0);
	ret[len] = '\0';
	if (n <= 0)
		ret[0] = (n == 0) ? '0' : '-';
	while (n != 0)
	{
		len--;
		ret[len] = (n > 0) ? base[(n % base_len)] : base[-(n % base_len)];
		n = n / base_len;
	}
	return (ret);
}
