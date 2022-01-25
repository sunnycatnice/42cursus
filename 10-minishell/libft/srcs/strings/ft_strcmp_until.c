/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:46:47 by bde-luca          #+#    #+#             */
/*   Updated: 2021/11/08 19:44:58 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp_until_inc(const char *s1, const char *s2, int c)
{
	long	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s2[i + 1] != c && s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - s2[i]);
}

int	ft_strcmp_until_exc(const char *s1, const char *s2, int c)
{
	long	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s2[i] != c && s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - s2[i]);
}
