/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <dmangola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:33:00 by dmangola          #+#    #+#             */
/*   Updated: 2021/11/04 20:22:02 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../../includes/ashella.h>

//write a function that will take 2 strings (str1 str2) and return the index of the first occurence of the str2 in the str1
void	ft_str_index(char *str1, char *str2)
{
	int i;
	int j;

	i = 0;
	while (str1[i])
	{
		j = 0;
		while (str2[j])
		{
			if (str1[i + j] != str2[j])
				break ;
			j++;
		}
		if (str2[j] == '\0')
			return (i);
		i++;
	}
	return (-1);
}
